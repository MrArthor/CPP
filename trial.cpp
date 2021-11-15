int sumArray (int * p, int n) {
int sum = 0, x;
int * ptr = p; 
int * pend = &p[n]; 

while (ptr != pend) {
x = *ptr; 
if (x> 5) sum = x + sum;
ptr++;
}
return sum;
}