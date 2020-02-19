import sys
import pygame
import colors
from ps_game import WIDTH, HEIGHT, OFFSET, TURN


STACKS_X = OFFSET
STACK_A_Y = 200
STACK_B_Y = 500
STACK_WIDTH = WIDTH - 2 * OFFSET
STACK_HEIGHT = 2

class Stacks:
	def __init__(self, numbers):
		self.a = Stack(STACKS_X, STACK_A_Y, numbers, self.count_positions(numbers))
		self.b = Stack(STACKS_X, STACK_B_Y, list(), self.count_positions(numbers))
		self.instructions = []
		self.get_instructions()
		self.len_instructions = len(self.instructions)
		self.moves_counter = 0
		self.instr_dict = {
			'sa': self.sa,
			'sb': self.sb,
			'ss': self.ss,
			'pa': self.pa,
			'pb': self.pb,
			'ra': self.ra,
			'rb': self.rb,
			'rr': self.rr,
			'rra': self.rra,
			'rrb': self.rrb,
			'rrr': self.rrr,
		}

	def update(self, turn):
		if self.moves_counter < turn <= self.len_instructions:
			if self.instructions[self.moves_counter] in self.instr_dict:
				self.instr_dict[self.instructions[self.moves_counter]]()


	def count_positions(self, numbers):
		len_numbers = len(numbers)
		positions = []
		i = 0
		for n in range(len_numbers):
			x = STACKS_X + (len_numbers - 1 - i) * (STACK_WIDTH / (len_numbers - 1))
			i += 1
			positions.append(x)
		return positions

	def sa(self):
		self.a.swap_numbers()
		self.moves_counter += 1

	def sb(self):
		self.b.swap_numbers()
		self.moves_counter += 1

	def ss(self):
		self.sa()
		self.sb()

	def pa(self):
		self.a.push_number(self.b.pop_number())
		self.moves_counter += 1

	def pb(self):
		self.b.push_number(self.a.pop_number())
		self.moves_counter += 1

	def ra(self):
		self.a.shift_up_numbers()
		self.moves_counter += 1

	def rb(self):
		self.b.shift_up_numbers()
		self.moves_counter += 1

	def rr(self):
		self.ra()
		self.rb()

	def rra(self):
		self.a.shift_down_numbers()
		self.moves_counter += 1

	def rrb(self):
		self.b.shift_down_numbers()
		self.moves_counter += 1

	def rrr(self):
		self.rra()
		self.rrb()

	def get_instructions(self):
		for instr in sys.stdin:
			self.instructions.append(instr[:-1])
		self.instructions.append('DONE')


class Stack(pygame.sprite.Sprite):
	def __init__(self, x, y, numbers, positions):
		pygame.sprite.Sprite.__init__(self)
		self.y = y
		self.size = 0
		self.numbers = numbers
		self.positions = positions
		self.image = pygame.Surface((STACK_WIDTH, STACK_HEIGHT))
		self.image.fill(colors.BLACK)
		self.rect = self.image.get_rect(midleft=(x, y))

	def update(self):
		if self.numbers:
			for n in self.numbers:
				n.rect.x = self.positions[self.numbers.index(n)]
				n.rect.centery = self.y



	def append_number(self, number):
		self.numbers.append(number)
		self.size += 1

	def push_number(self, number):
		self.numbers.insert(0, number)

	def swap_numbers(self):
		self.numbers[0], self.numbers[1] = \
			self.numbers[1], self.numbers[0]

	def pop_number(self):
		self.size -= 1
		return self.numbers.pop(0)

	def shift_up_numbers(self):
		self.numbers.append(self.numbers.pop(0))

	def shift_down_numbers(self):
		self.numbers.insert(0, self.numbers.pop())

	def add_numbers(self, numbers):
		for n in numbers:
			self.append_number(n)


