def main():
	#print "test"
	happy = int(input("Types a non-null Natural number to checks your happiness :"))
	if happy<1:
		print ("I say \"...a non-null Natural number...\", your ##!@#$ ")
		return 0
	n=happy	
	while n!=1:
		n=str(n)
		soma=0
		i=0
		while i<len(n):
			aux=int(n[i])**2
			print ("the square of "+n[i]+" is :"+str(aux))
			soma+=aux
			i+=1
		print ("them sum is: "+str(soma))
		n=soma
		soma=0
		i=0
	print (str(happy)+" is a happy number!!")
		
		
	#print "passou"
	return 0



main()
