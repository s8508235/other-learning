import re
def f(input_string):
    ans = []
    pattern = re.compile('(\w+)(\s*)')
    for word in pattern.findall(input_string):
        # print(word)
        ans.append(word[0][::-1])
        ans.append(word[1])
    
    return ''.join(ans)

txt = "welcome  to the jungle"
print(f(txt))
print(f('flipped class room is important'))