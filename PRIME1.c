#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
 
char buffer[4096];
int bufcount =0;
int b_primes[39] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47
		,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113
		,127,137,139,149,151,157,163,167,173};
 void inline putbuff(char *buf, int ind) {
	if((4096-bufcount) < 12) {
		fwrite(buffer, bufcount, 1, stdout);
		bufcount=0;
		buffer[0]='\0';
	}
 	while(ind<12){
		buffer[bufcount] = buf[ind];
		ind++;
		bufcount++;
	}
	bufcount-=1;
}
 
int main() {
 
	int numset = 0, lower=0, upper = 0;
	scanf("%d", &numset);
	int i=0, j=0, k=0, l=0, m=0;
	int rangediff=0;
 	double div = 0;
 	int PP[31622] = {0}; 
 	for(i=0;i<39;i++) {
		j=b_primes[i];
		k=j+j;
		while(k<31622) {
			PP[k] = 1;
			k+=j;
		}
	}
 	int PP_count = 0;
	int PP_t[31622];
 	for(i=2;i<31622;i++) {
		if(PP[i] == 0) {
			PP_t[PP_count] = i;
			PP_count+=1;
		}
	}
	char A[100000] = {0};
 	for(i=0;i<numset;i++) {
		scanf("%d %d",&lower, &upper);
		rangediff = upper-lower;
		if(lower==1)
			A[0] = 1;
		for(j=0;j<PP_count;j++) {
 			k=PP_t[j];
			if(upper > k) {
				div=((double)lower)/k;
				l = ceil(div);
 				if(l==1||l==0)
					m=k+k-lower;
				else
					m=(l)*k-lower;
				while(m<=rangediff) {
					A[m]=1;
					m+=k;
				}
			}
		}
 		int c_count=0;
		char temp_b[12];
		char loop_b[12] = {'0','0','0','0','0','0','0','0','0','0','\n','\0'};
		int len=0;
		int index = 0;
 		int prev_prime = -1;
		int diff_cons_prime = 0;
 		m=0;
 		for(j=lower; j<=upper;j++,m++) {
			if(A[m]==0) {
				snprintf(temp_b,12,"%d",j);
				len=strlen(temp_b);
				k=0;
				for(l=10-len;l<10;l++,k++)
					loop_b[l] = temp_b[k];
				index = 10-len;
				prev_prime = j;
				putbuff(loop_b,index);
				break;
			}
			A[m]=0;
		}
		int h=0, digit=0;
		m+=1;
		int loop_ind = 10-len;
		if(prev_prime < 0) {
			continue;
		}
		for(j=prev_prime+1;j<=upper;j++) {
			if(A[m]==0) {
 				diff_cons_prime = j-prev_prime;
				h=9;
				while(h) {
					digit = diff_cons_prime%10;
					diff_cons_prime/=10;
					loop_b[h] += digit;
					if(loop_b[h] > '9') {
						loop_b[h]-=10;
						diff_cons_prime+=1;
					}
					if(diff_cons_prime==0)
						break;
					h-=1;
				}
				if(h<loop_ind)
					loop_ind = h;
				prev_prime = j;
 				putbuff(loop_b,loop_ind);
			}
			A[m]=0;
			m++;
		}
		buffer[bufcount] = '\n';
		fwrite(buffer,bufcount+1,1,stdout);
		bufcount=0;
		buffer[bufcount]='\0';
	}
	return 0;
} 
