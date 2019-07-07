import re

class GetMenuCode:
	def __init__(self,oldFile):
		dict = {}
		self.oldSource = {}
		findCallback = re.compile("The following callback\sis\sfor\s\((\".*?\")\)")
		findStart = re.compile('Manual Code Start')
		findEnd = re.compile('Manual Code End')
		with open(oldFile) as f:
					for line in f:
						callback = findCallback.findall(line)
						startOfCode = findStart.findall(line)
						if(callback):
							#print 'call back '+callback[0]
							dictIndex = callback[0]
							dict[dictIndex] = ''
						if(startOfCode):
							while True:
								line = f.next()
								endOfCode = findEnd.findall(line)
								if(endOfCode):
									break
								else:
									dict[dictIndex] += line
		for index in dict:
			if dict[index] != '\n':
				self.oldSource[index] = dict[index]
				
if __name__== "__main__":	
	OldCodeObj = genMenuCode("GenMenu.c")
	#just example to read the interfaces with manual code added
	for index in OldCodeObj.oldSource:
		print index
	#print OldCodeObj.oldSource[index]