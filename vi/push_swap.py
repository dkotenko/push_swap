import pygame
import sys
#import commands
from stacks import Stacks, Stack, STACK_B_Y, STACK_A_Y
from ps_numbers import PS_Numbers, PS_Number
import colors
from ps_game import WIDTH, HEIGHT, FPS, TURN, OFFSET
from ps_speed import Speed



TURN_PARTS = 4
TIME_IN_SECONDS = 0
#PUSH_SWAP VARS

STATE = 'running'

BG_COLOR = pygame.Color('gray12')



def text_to_screen(text, color):
	text_on_screen = myfont.render(text, False, color)
	return text_on_screen


def draw_game():
	all_sprites.update()
	screen.fill(colors.BEIGE)
	#
	screen.blit(text_to_screen('TAIL', colors.BLACK), (10, STACK_A_Y + (STACK_B_Y - STACK_A_Y) / 2))
	screen.blit(text_to_screen('HEAD', colors.BLACK), (WIDTH - OFFSET * 2, STACK_A_Y + (STACK_B_Y - STACK_A_Y) / 2))

	#
	screen.blit(text_to_screen('MOVES', colors.BLACK), (50, 50))
	screen.blit(text_to_screen(str(stacks.moves_counter), colors.WHITE), (180, 50))
	screen.blit(text_to_screen('TIME', colors.BLACK), (350, 50))
	screen.blit(text_to_screen(str(TIME_IN_SECONDS), colors.WHITE), (450, 50))
	screen.blit(text_to_screen('CURRENT INSTRUCTION', colors.BLACK), (650, 50))
	if (stacks.moves_counter < stacks.len_instructions):
		screen.blit(text_to_screen(stacks.instructions[stacks.moves_counter], colors.WHITE), (1050, 50))	
	all_sprites.draw(screen)
	pygame.display.flip()
	return


# Создаем игру и окно
pygame.init()

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("1")
clock = pygame.time.Clock()

numbers = PS_Numbers()
numbers_sprites = pygame.sprite.Group()

stacks = Stacks(numbers.numbers)
stacks_sprites = pygame.sprite.Group()
stacks_sprites.add(stacks.a)
stacks_sprites.add(stacks.b)
stacks.get_instructions()

#ALL SPRITES GROUP
all_sprites = pygame.sprite.Group()
all_sprites.add(stacks.a)
all_sprites.add(stacks.b)
for n in numbers.numbers:
	all_sprites.add(n)
	numbers_sprites.add(n)

speed = Speed()


myfont = pygame.font.SysFont('arialboldttf', 30)
running = True
#время в игре
start_time =  0
prev_time = 0
prev_turn = 0
while running:
	# Ввод процесса (события)
	for event in pygame.event.get():
		# проверка для закрытия окна

		if event.type == pygame.QUIT:
			running = False
		elif event.type == pygame.KEYDOWN:
			if event.key == pygame.K_ESCAPE:
				running = False
			elif event.key == pygame.K_SPACE:
				if STATE == 'running':
					STATE = 'pause'
				elif STATE == 'pause':
					STATE = 'running'

			# клавиши увеличения/уменьшения скорости игры, не работают
			elif event.key == pygame.K_EQUALS:
				speed.speed_increase()
			elif event.key == pygame.K_MINUS:
				speed.speed_decrease()

	# пока пауза - выводим текущее состояние
	if STATE == "pause":
		all_sprites.draw(screen)
		continue

	# Рендеринг

	draw_game()

	# Держим цикл на правильной скорости
	clock.tick(FPS)
	# счетчик ходов
	if not start_time:
		start_time = pygame.time.get_ticks()
	time_since_enter = pygame.time.get_ticks() - start_time

	# print(time_since_enter // 1000, TURN)
	if time_since_enter // (1000 // speed.speed) > prev_turn // (1000 // speed.speed):
		TURN += 1
		stacks.update(TURN)
		prev_turn = time_since_enter

	if time_since_enter // (1000) > prev_time:
		TIME_IN_SECONDS += 1
		prev_time = time_since_enter // (1000)	

#выход
#pygame.quit()
