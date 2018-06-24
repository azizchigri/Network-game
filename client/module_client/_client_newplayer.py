#!/usr/bin/python3.6

import math

def search_most_food(self, loot_places):
	food_places = []
	for loot in loot_places:
		food_places.append(loot.count("food"))
	max_food = max(food_places)
	if max_food == 0:
		return -1
	max_food_places = []
	for i, foods in enumerate(food_places):
		if foods is max_food:
			max_food_places.append(i)
	return max_food_places

def go_to_food_place(self, dest):
	nb_forward = int(math.sqrt(dest))
	for i in range(0, nb_forward):
		if self.forward() == 84:
			return 84
	pos = nb_forward * nb_forward + nb_forward
	if pos > dest:
		if self.left() == 84:
			return 84
	elif pos < dest:
		if self.right() == 84:
			return 84
	while pos != dest:
		if self.forward() == 84:
			return 84
		if pos > dest:
			pos -= 1
		else:
			pos += 1
	return 0

def get_ressources(self):
	if self.look() == 84:
		return 84
	loot_places = self.looked.split(",")
	max_food = self.search_most_food(loot_places)
	if max_food == -1:
		if self.left() == 84:
			return 84
		if self.forward() == 84:
			return 84
		return 0
	self.go_to_food_place(max_food[0])
	for ressource in self.ressources_name:
		nb_res = loot_places[max_food[0]].count(ressource)
		i = 0
		while i < nb_res:
			if self.take_item(ressource) == 84:
				return 84
			i += 1
	return 0

def roles(self, message):
	if int(self.id) == 0:
		if self.queen(message) == 84:
			return 84
	else:
		if self.master() == 84:
			return 84
	return 0

