import sys
import pygame
from stacks import STACKS_X, STACK_A_Y, STACK_WIDTH
import colors

NUMBER_MAX_WIDTH = 200
NUMBER_MIN_WIDTH = 10
NUMBER_HEIGHT = 2

class PS_Numbers():
	def __init__(self):
		self.numbers = []
		self.numbers_counter = 0
		self.numbers_val = self.get_numbers()
		self.numbers_sorted = sorted(self.numbers_val)
		self.add_numbers()

	def add_number(self, value, x, y, width):
		n = PS_Number(value, x, y, width)
		self.numbers.append(n)
		self.numbers_counter += 1
		return n

	def add_numbers(self):
		len_numbers = len(self.numbers_val)
		i = 0
		delta_size = (NUMBER_MAX_WIDTH - NUMBER_MIN_WIDTH) / len(self.numbers_val)
		for n in self.numbers_val:
			x = STACKS_X + (len_numbers - 1 - i) * (STACK_WIDTH / (len_numbers - 1))
			width = NUMBER_MIN_WIDTH + delta_size * self.numbers_sorted.index(n)
			self.add_number(n, x, STACK_A_Y, width)
			i += 1

	def get_numbers(self):
		def stdin_numbers():
			s = []
			if len(sys.argv) < 2:
				print('No arguments. Stop')
				exit()
			f = None
			if len(sys.argv) == 2:
				if sys.argv[1] == 'Error':
					print('Error')
					exit()
				try:
					f = open(sys.argv[1], "r")
				except FileNotFoundError:
					print("Can`t open the file")
					exit()
				temp = [l.split() for l in [line.rstrip() for line in f]]
				for t in temp:
					for number in t:
						s.append(int(number))
				f.close()
			return s
		s = stdin_numbers()
		if not s:
			i = 0
			for arg in sys.argv:
				if not i:
					i += 1
					continue
				if arg.find(' '):
					splitted = arg.split()
					for n in splitted:
						s.append(int(n))
				else:
					s.append(int(arg))
		return s


class PS_Number(pygame.sprite.Sprite):
	def __init__(self, value, x, y, width):
		pygame.sprite.Sprite.__init__(self)
		self.value = value
		self.width = width
		self.height = NUMBER_HEIGHT
		self.x = x
		self.y = y
		self.image = pygame.Surface((NUMBER_HEIGHT, self.width))
		self.image.fill(colors.BLACK)
		self.rect = self.image.get_rect(center=(self.x, self.y))

	def update(self):
		pass
