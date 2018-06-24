#!/usr/bin/python3.6

def master(self):
	while (1):
		if self.inventory() == 84:
			return 84
		if self.get_ressources() == 84:
			return 84
		message = self.check_messages("IncantNow")
		if message is not None and self.ressources[0] >= 25:
			self.follow_incant(message)
		i = 0
		check_incant = True
		while i < len(self.ressources_incant[self.level]) and check_incant is True:
			if self.ressources[i + 1] < self.ressources_incant[self.level][i]:
				check_incant = False
			i += 1
		if check_incant is True and self.ressources[0] > 25:
			if self.try_incant() == 84:
				return 84

def follow_incant(self, message):
	while message is None or (not "0" in message[0][8]
			and "IncantNow" in message[4]):
		if message is None:
			if self.look() == 84:
				return 84
		elif "IncantFail" is message[4] or "IncantConfirm" \
				is message[4]:
			return 0
		else:
			direction = int(message[0][8])
			if self.follow[direction] == 84:
				return 84
		message = self.check_messages("Incant")
	if "IncantFail" is message[4] or "IncantConfirm" is message[4]:
		return 0
	if self.broadcast(":" + self.team + ":" + self.id + ":"
			+ message[2] + ":IncantOk") == 84:
		return 84
	while message is None or "IncantNow" in message[4]:
		if self.look() == 84:
			return 84
	if message[4] is "IncantFail":
		return 0
	return 0



def try_incant(self):
	nb_client = 1
	client_incant = ""
	k = 0 if (self.level == 1 or self.level % 2 == 0) else 1
	while self.ressources[0] > 15 and nb_client < (self.level - k):
		if self.broadcast(":" + self.team + self.id + ":all:"
		+ ":IncantNow:" + self.level) == 84:
			return 84
		message = self.check_messages("IncantOK")
		if message is not None:
			if client_incant is not None:
				client_incant += ","
			client_incant += message[2]
	if nb_client == (self.level - k):
		if self.do_incant(client_incant) == 84:
			return 84
	else:
		if self.broadcast(":" + self.team + self.id + ":all:" + ":IncantFail") == 84:
			return 84
		if self.broadcast(":" + self.team + self.id + ":all:" + ":IncantFail") == 84:
			return 84
		if self.broadcast(":" + self.team + self.id + ":all:" + ":IncantFail") == 84:
			return 84
	return 0

def do_incant(self, clients):
	if self.broadcast(":" + self.team + self.id + ":all:"
			+ ":IncantConfirm:" + clients) == 84:
		return 84
	for i, j in enumerate(self.ressources_incant[self.level - 1]):
		while j != 0:
			if self.set_item(self.ressources_name[i + 1]) == 84:
				return 84
			j -=1
	if self.incantation() == 84:
		return 84
	return 0