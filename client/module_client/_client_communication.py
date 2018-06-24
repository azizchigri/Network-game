
import ctypes

def check_dead(self):
	if self.is_alive is True:
		return 0
	return 84

def send(self, message_string):
	print(message_string)
	enc_message = message_string.encode('utf-8')
	message = ctypes.create_string_buffer(enc_message)
	if self.ia_com.client_send(self.sock_fd, message) == 84:
		return 84
	return 0

def receive(self):
	is_number = False
	self.buff_str = ""
	while (not self.buff_str.startswith('[') and is_number is False
			and not self.buff_str.startswith("Elevation underway")
			and not self.buff_str.startswith("Current level")
			and not self.buff_str.startswith("ok")
			and not self.buff_str.startswith("ko")):
		if self.ia_com.client_receive(
			self.sock_fd, self.buffer)== 84:
			return 84
		self.buff_str = self.buffer.value.decode(
				'utf-8').split("\n", 1)[0]
		print(self.buff_str)
		try:
			int(self.buff_str)
			is_number = True
		except ValueError:
			is_number = False
		if self.check_buff() == 84:
			return 84
	return 0

def check_buff(self):
	if self.buff_str.startswith("dead"):
		self.isAlive = False
		return 84
	if self.team in self.buff_str:
		self.memory_message.append(self.buff_str)
	elif "Elevation underway" in self.buff_str:
		self.memory_message.append("message 0, :" + self.team + ":"
				+ self.id + ":" + self.id
				+ ":" + self.buff_str)
	self.res = True if self.buff_str.startswith("ok") \
			or self.buff_str.startswith("Current level") else False


def check_messages(self, action):
	for message in self.memory_message:
		if ":" + self.team + ":" in message:
			m_split = message.split(":")
			if ("all" in m_split[3] or (m_split[3] == self.id)) and action in m_split[4]:
				self.memory_message = []
				return m_split
	self.memory_message = []
	return None

