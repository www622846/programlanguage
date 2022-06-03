"""wordset = set()
for word in words:
	string = ''
	for ch in word:
		if ch.isalpha() or ch == '~':
			string += ch
	if string != '':
		wordset.add(string)
"""

f = open('copy.txt', 'r')
words = f.read().split()
result = {}
for word in words:
    word = word.lower()
    if word in result:
        result[word] += 1
    else:
        result[word] = 1

w = open('copyproverb.txt', 'w')
for i in sorted(result.items()):
    print('{} : {}'.format(i[0], i[1]))
    w.write(i[0]+ ' : ' + str(i[1]) + '\n')
w.close()
f.close()
