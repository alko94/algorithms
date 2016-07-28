
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

def insert(root,key):
	if root == None:
		return node(key)
	elif key<root.key:
		root.left = insert(root.left,key)
	else: #root.key>=key
		root.right = insert(root.right,key)
	root.height = max(height(root.left),height(root.right)) +1 #height_mode
	return root

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
	return x,root	

#x - minimalny element, y - drzewo z usunietym minimalnym elementem
def removeMin(root):
	if not root.left:
		return root,root.right
	x,y = removeMax(root.left)
	root.left = y
	root.height = max(height(root.left),height(root.right)) +1 #height_mode
	return x,root


def remove(root,key):
	if root == None:
		return None
	if key<root.key:
		root.left = remove(root.left,key)
		root.height = max(height(root.left),height(root.right)) +1 #height_mode
		return root
	elif root.key<key:
		root.right = remove(root.right,key)
		root.height = max(height(root.left),height(root.right)) +1 #height_mode
		return root
	else:
		#root.key == key
		if root.left:
			x,y = removeMax(root.left)
			x.left = y
			x.right = root.right
			#garbage collecting - /*delete root;*/ in cpp
			x.height = max(height(x.left),height(x.right)) +1 #height_mode
			return x
		elif root.right:
			x,y = removeMin(root.right)
			x.left = root.left
			x.right = y
			#garbage collecting - /*delete root;*/ in cpp
			x.height = max(height(x.left),height(x.right)) +1 #height_mode
			return x
		else:
			#garbage collecting - /*delete root;*/ in cpp
			return None

#-------------------------------------------------------------------------------


#root = None
#ba = [11,10,9,13,7,2,3,1,5,8]
#for b in ba:
#	root = insert(root,b)

