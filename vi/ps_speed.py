class Speed:
	def __init__(self):
		self.speed_tuple = (1, 2, 4, 8, 16, 32, 64)
		self.speed_choice = 1
		self.speed = self.speed_tuple[self.speed_choice]

	def speed_increase(self):
		if self.speed_choice < len(self.speed_tuple) - 1:
			self.speed_choice += 1
			self.speed = self.speed_tuple[self.speed_choice]

	def speed_decrease(self):
		if self.speed_choice > 0:
			self.speed_choice -= 1
			self.speed = self.speed_tuple[self.speed_choice]

	def get_speed(self):
		return 'x%.2f' % self.speed

	def __repr__(self):
		return 'SPEED = %d' % self.speed