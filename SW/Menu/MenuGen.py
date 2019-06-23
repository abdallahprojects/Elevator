import re
class item:
	def __init__(self,text,id=0):
		self.text = text
		self.id = id
		self.firstChild = self
		self.nextItem = self
		self.prevItem = self
		self.parent = self
		self.actionListener = True
		self.isFirstChild = False
class itemStack:
	def __init__(self):
		self.items = []
		self.size = 0
		self.lastItem = self
	def AddItem(self,item):
		self.size +=1
		self.items.append(item)
		if(self.size>1):
			itemsList = self.items
			for idx in range(len(itemsList)):
				itemsList[idx].nextItem = itemsList[(idx+1)%len(itemsList)]
				itemsList[idx].prevItem = itemsList[idx-1]
				itemsList[(idx+1)%len(itemsList)].parent = itemsList[idx].parent
class menu:	
	def __init__(self,inputFile):
		findTabs = re.compile("(\t)")
		findAction = re.compile("\[(.*?)\]")
		index = 0
		self.items = {}
		stacks = {}
		stackIndex = 0
		preTab = 0
		stacks[0] = itemStack()
		with open(inputFile) as f:
			for line in f:
				Tabs = findTabs.findall(line)
				Actions = findAction.findall(line)
				text = Actions[0]
				#print Actions[0] #Actions[0] = text, Actions[1] (if exists) = call back funtion required (yes or no)
				action = True
				if len(Actions)>1:
					if(Actions[1].lower() == 'no'):
						action = False
					elif(Actions[1].lower() == 'yes'):
						action = True
					else:
						print "Wrong action quitting ..."
						quit()
					#everything is ready
				self.items[index] = item(Actions[0],index)
				self.items[index].actionListener = action
				#print len(Tabs)
				if len(Tabs) == (preTab+1): #starting new child (first child)
					stackIndex +=1
					self.items[index-1].firstChild = self.items[index]
					self.items[index].parent = self.items[index-1]
					self.items[index].isFirstChild = True
					stacks[stackIndex] = itemStack()
					stacks[stackIndex].AddItem(self.items[index])
					
				elif len(Tabs) < (preTab): #leave sub menu (end stack level)
					#close stacks till the new len(Tabs) and process them
					while stackIndex > len(Tabs):
						del stacks[stackIndex]
						stackIndex -=1
					stacks[stackIndex].AddItem(self.items[index])
				elif len(Tabs) > (preTab +1):
					print "Wrong File Format"
					quit()
				else: #both are equal (same level)
					stacks[stackIndex].AddItem(self.items[index])
				index+=1;
				preTab = len(Tabs)

class createHeader:
	def __init__(self,fileName,Menu):
		f= open(fileName+".h","w+")
		f.write("// Call backs funtion prototypes:\n")
		f.write("void stubCall(void);\n")
		for idx,item in Menu.items.items():
			if(item.actionListener):
				f.write("// The following callback is for ("+item.text+") menu item \n")
				f.write("void callBack"+str(item.id)+"(void);\n")
		f.write("// Defining the menu items structs in flash memory\n")
		f.write( "const menuItem_t menuItems[] 	= {\n")
		for idx,item in Menu.items.items():
			f.write( 9*'\t' + "{"+"\n")
			f.write( 9*'\t' +" //  This is element number ("+str(idx)+')' +" calling -> "+str(item.firstChild.id)+"\n")
			f.write( 9*'\t ' +item.text +","+"\n")
			if item.actionListener:
				f.write( (9*'\t')+' &callBack' +str(idx) +","+"\n")
			else:
				f.write( (9*'\t')+' &stubCall' +","+"\n")
			#Check for Parent 
			f.write( (9*'\t')+' &menuItems[' +str(item.parent.id) +"],"+"\n")
			#Check for Next
			f.write( (9*'\t')+' &menuItems[' +str(item.nextItem.id) +"],"+"\n")
			#Check for Prev
			f.write( (9*'\t')+' &menuItems[' +str(item.prevItem.id) +"],"+"\n")
			if idx == (len(Menu.items)-1):
				f.write( 9*'\t' +"}"+"\n")
			else:
				f.write( 9*'\t' +"},"+"\n")
		f.write( 8*'\t' +"  };"+"\n")
		f.close()

class createSource:
	def __init__(self,fileName,Menu):
		f= open(fileName+".c","w+")
		f.write("// Call backs funtion implementation:\n")
		for idx,item in Menu.items.items():
			if(item.actionListener):
				f.write("// The following callback is for ("+item.text+") menu item \n")
				f.write("void callBack"+str(item.id)+"(void){\n")
				f.write("\tcurrentMenuItem = &menuItems["+str(item.firstChild.id)+"];\n}\n")
		f.close()
		
if __name__== "__main__":
	Menu = menu("Menu\inputScript.txt")
	createHeader("Menu\GenMenu",Menu)
	createSource("Menu\GenMenu",Menu)

