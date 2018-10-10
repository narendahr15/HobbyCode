
file = open("testOut", "r")
fileContent = file.read()

if(fileContent[0] == '\x7f' and fileContent[1] == '\x45'):
	print  "Elf file"
else:
  	print "Not an elf file"
	print fileContent[0]
	print fileContent[1]

for x in range(0,5):
	print fileContent[x]
#print fileContent
