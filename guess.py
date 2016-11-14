import itertools
from builtins import input
global_set_fk = set((itertools.permutations('1234567890', 4)))
def check(Ans,G):
	A=0
	for i in range (4):
		if(G[i] == Ans[i]):
			A+=1
	C = set(G)
	D = set(Ans)
	my_check_len = C & D
	#print len(my_check_len)
	B = len(my_check_len) - A # how many B
	#print A,B
	return A,B

def my_del(A,B,my_guess_num):
	#print "my_del :"+" "+ str(A) +"A" + str(B) + "B"
	ans_set = set()
	for set_num in global_set_fk:
		#print "Test:"+str(set_num)
		my_num = ''.join(set_num)
		#print "my_num:" + str(my_num)
		my_A,my_B = check(my_num,my_guess_num)
		if(my_A == A and my_B == B):
			ans_set.add(set_num)
			#print ans_set
	#print "Ans set:"+str(len(ans_set))
	global_set_fk.intersection_update(ans_set)
	#print "After del Global set length:"+str(len(global_set_fk))

def guess(Round):
	make_num = "".join(global_set_fk.pop()) 
	guess_num_list = list(guess_num)
	#print len(global_set_fk)
	A,B =check(make_num,guess_num_list)
	print ("Round-"+str(Round)+" " + "".join(make_num)+" "+ str(A) +"A" + str(B) + "B")
	if(A == 4):
		print ("Correct!\n")
	else:
		my_set = my_del(A,B,make_num)
		guess(Round+1)

def enter_num():
	global guess_num
	guess_num = input("Please enter a non-repeat 4-digit number:")	
	if(len(str(guess_num)) is not 4 or len(set(list(guess_num))) is not 4):
		print ("Wrong input!\nEnter again.")
		return 0
	else: 
		return 1
#print len(set(list(guess_num)))
#for checking global set

while(1):
	if(enter_num() is 1):
		break
if __name__ == "__main__":
	guess(1)