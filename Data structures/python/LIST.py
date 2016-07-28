class node(object):
	"""docstring for node"""
	def __init__(self,key=None):
		self.key = key
		self.next = None
	def __repr__(self):
		return `self.key` +', '+`self.next`

class LIST(object):
	"""docstring for LIST"""
	def __init__(self):
		self.head = None
	
	def __repr__(self):
		return '['+`self.head`+']'
	
	def insert(self,key): #addSorted
		cur = node(key)
		if not self.head or key < self.head.key:
			cur.next = self.head
			self.head = cur
		else:
			prev = self.head
			while prev.next and prev.next.key<key:
				prev = prev.next
			if not prev.next:
				prev.next = cur
			else:
				cur.next = prev.next
				prev.next = cur
	
	def findMax(self):
		p = self.head
		if p:
			while p.next:
				p = p.next
		return p
	
	def findMin(self):
		return self.head
	
	def find(self,key):
		p = self.head
		while p and p.key < key:
			p = p.next
		if p and p.key == key:
			return p
		return None
	
	def remove(self,key):
		if self.head:
			if self.head.key == key:
				#toDel = head
				self.head = self.head.next
				#delete head;
			else:
				prev = self.head
				while prev.next and prev.next.key<key:
					prev = prev.next
				if prev.next and prev.next.key==key:
					#toDel = prev.next
					prev.next = prev.next.next
					#delete toDel

