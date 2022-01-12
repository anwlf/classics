/********************************
*	classics.c		*
*        Test                   *
*********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Fibonachi algorithm
int fib(int n) {
    int fn_1=0;
    int fn_2=1;
    int fn_3;
    //printf("0 1 ");
    for (int i=2; i<n+2; ++i) {
	fn_3 = fn_1 + fn_2;
	printf("%d ",fn_3);
	fn_1=fn_2;
	fn_2=fn_3;
    }
    printf("\n");
    return fn_3;
}

//Fibonachi algorithm with recursion
int fib_rec(int n) {
    static int n1=0,n2=1,n3=3;
    //printf("0 1 ");
    if (n>0) {
	n3=n1+n2;
	n1=n2;
	n2=n3;
	printf("%d ",n3);
	fib_rec(n-1);
    } else printf("\n");
    return n3;
}

//Check for Prime number
int prime(int n) {
    int m=n/2;
    for (int i=2;i<=m;++i) {
	if (n%i==0) {
	    printf("%d not prime\n",n);
	    return 0;
	}
    }
    printf("%d prime\n",n);
    return 1;
}

int check_prime(int n) {
    int m=n/2;
    for (int i=2;i<=m;++i) {
	if (n%i==0)  return 0;
    }
    return 1;
}

void list_n_primes(int n) {
    printf("list of %i primes: ");
    int i=0,j=0;
    do {
	if (check_prime(i)==1) {
	    printf("%d ",i);
	    j++;
	}
	i++;
    } while (j<n);
    printf("\n");
}

//Check for Palindrome 10 number
int palindrome_10(int n) {
    int r,s=0,t;
    t=n;
    while (n>0) {
	r=n%10;
	s=(s*10)+r;
	n/=10;
    }
    if (s==t) {
	printf("%d palindrome on base 10\n",t);
    } else {
	printf("%d not palindrome on base 10\n",t);
    }
    return (s==t);
}

//Factorial
long int fact(int n) {
    int f=1;
    for (int i=1; i<=n; ++i) {
	f=f*i;
    }
    return f;
}

//Factotial recurusive
long int fact_rec(int n) {
    return (n==0)?1:(n*fact_rec(n-1));
}

//Reverse numbers
long int reverse_10(long int n) {
    int rev=0,rem;
    while (n!=0) {
	rem=n%10;
	rev=rev*10+rem;
	n/=10;
    }
    return rev;
}

int narcissistic(int n){
    int a,d=0,m,sum=0;
    printf("%d",n);
    m=n;
    //for counting the number of digits in number
    while(m>0){
        m=m/10;
        d++;
    }
    m=n;
    while(n>0){
        a=n%10;
        sum=sum+pow(a,d);
        n=n/10;
    }
    if(sum==m) {
	printf(" is narcissistic\n");
	return 1;
    }
    printf(" is not narcissistic\n");
    return 0;
}

int main(int argc, char** args) {
    int  number = 3;
    if (argc>1) number = atoi(args[1]);
    int fib_num=(number>31)?31:number;
    printf("fibonacci in loop up to 31, n=%d: ",fib_num);
    fib(fib_num);
    printf("fibonacci recurs. up to 31, n=%d: ",fib_num);
    fib_rec(fib_num);
    prime(number);
    list_n_primes(number);
    palindrome_10(number);
    narcissistic(number);
    int fact_num = (number>31)?31:number;
    printf("factorial in loop: %d!=%ld\n",fact_num,fact(fact_num));
    printf("factorial recurs.: %d!=%ld\n",fact_num,fact_rec(fact_num));
    printf("%d reverse in 10: %ld\n",number,reverse_10((long int)number));
    return 0;
}
