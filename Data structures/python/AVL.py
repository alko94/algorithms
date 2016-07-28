
class node(object):
	"""a node is a node"""
	def __init__(self, key, left=None, right=None):
		super(node, self).__init__()
		self.key = key
		self.left = left
		self.right = right
		self.height = 1 #height_mode
	
	def __repr__(self):
		return '['+`self.key`+','+`self.left`+','+`self.right`+']'
		#return `self.key` + '\n' +'L.'+ `self.left` +'\n'+ 'R.'+ `self.right`

def treePrint(self,n=0):
		if self == None:
			return ''
		return treePrint(self.left,n+1)+ '\n' +' .'*(30-n) +`self.key` + treePrint(self.right,n+1)


def height(root): #height_mode
	if root == None:
		return 0
	return root.height

def balance(root):
	if root == None:
		return 0
	return height(root.right) - height(root.left)

def rotateLeft(root):
	rightAtFirst = root.right
	transfer = rightAtFirst.left
	
	root.right = transfer
	rightAtFirst.left = root
	
	root.height = max(height(root.left),height(root.right)) +1
	rightAtFirst.height = max(height(rightAtFirst.left),height(rightAtFirst.right)) +1
	
	return rightAtFirst

def rotateRight(root):
	leftAtFirst = root.left
	transfer = leftAtFirst.right
	
	root.left = transfer
	leftAtFirst.right = root
	
	root.height = max(height(root.left),height(root.right)) +1
	leftAtFirst.height = max(height(leftAtFirst.left),height(leftAtFirst.right)) +1
	
	return leftAtFirst


#def balanced(root):
#	b = balance(root)
#	if b < -1:
#		b2 = balance(root.left)
#		if b2 <=0: #LL case
#			root = rotateRight(root)
#		elif b2 == 1: #LR case
#			root.left = rotateLeft(root.left)
#			root = rotateRight(root)
#	elif b>1:
#		b2 = balance(root.right)
#		if b>=0: #RR case
#			root = rotateLeft(root)
#		elif b==-1: #RL case
#			root.right = rotateRight(root.right)
#			root = rotateLeft(root)
#	return root


def balanced(root):
	b = balance(root)
	if b < -1:
		b2 = balance(root.left)
		if b2 <=0: #LL case
			return rotateRight(root)
		if b2 == 1: #LR case
			root.left = rotateLeft(root.left)
			return rotateRight(root)
	if b>1:
		b2 = balance(root.right)
		if b>=0: #RR case
			return rotateLeft(root)
		if b==-1: #RL case
			root.right = rotateRight(root.right)
			return rotateLeft(root)
	return root


def insert(root,key):
	if root == None:
		return node(key)
	elif key<root.key:
		root.left = insert(root.left,key)
	else: #root.key>=key
		root.right = insert(root.right,key)
	root.height = max(height(root.left),height(root.right)) +1
	return balanced(root)

def findMax(root):
	r = root
	while r.right: r=r.right
	return r

def findMin(root):
	r = root
	while r.left: r = r.left
	return r

def find(root, key):
	r = root
	while r and r.key != key:
		if key < r.key:
			r = r.left
		else:
			r = r.right
	return r

#x - maksymalny element, y - drzewo z usunietym maksymalnym elementem
def removeMax(root):
	if not root.right:
		return root,root.left
	x,y = removeMax(root.right)
	root.right = y
	root.height = max(height(root.left),height(root.right)) +1 #height_mode
	return x,balanced(root)

#x - minimalny element, y - drzewo z usunietym minimalnym elementem
def removeMin(root):
	if not root.left:
		return root,root.right
	x,y = removeMax(root.left)
	root.left = y
	root.height = max(height(root.left),height(root.right)) +1 #height_mode
	return x,balanced(root)

def remove(root,key):
	if root == None:
		return None
	if key<root.key:
		root.left = remove(root.left,key)
		root.height = max(height(root.left),height(root.right)) +1 #height_mode
		return balanced(root)
	elif root.key<key:
		root.right = remove(root.right,key)
		root.height = max(height(root.left),height(root.right)) +1 #height_mode
		return balanced(root)
	else:
		#root.key == key
		if root.left:
			x,y = removeMax(root.left)
			x.left = y
			x.right = root.right
			#garbage collecting - delete root in cpp /*delete root;*/
			x.height = max(height(x.left),height(x.right)) +1 #height_mode
			return balanced(x)
		elif root.right:
			x,y = removeMin(root.right)
			x.left = root.left
			x.right = y
			#garbage collecting - delete root in cpp /*delete root;*/
			x.height = max(height(x.left),height(x.right)) +1 #height_mode
			return balanced(x)
		else:
			#garbage collecting - delete root in cpp /*delete root;*/
			return None

#-------------------------------------------------------------------------------------------
#
#root = None
#ba = [11,10,9,13,7,2,3,1,5,8]
#for b in ba:
#	root = insert(root,b)

#print treePrint(root)


#ba = [25,19,30,15,35,10,40,5,45,20,22,21,24,23]
#ba = [10,3,8,9,12,16,5,2,1,11]
