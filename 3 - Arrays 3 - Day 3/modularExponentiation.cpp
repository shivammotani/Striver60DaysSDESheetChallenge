int modularExponentiation(long long int x, int n, int m) {
	// Write your code here.
	long long int ans = 1;
	while(n>0){
		if (n % 2 == 0) {
			x = (x*x)%m;
			n /= 2;
		} 
		else{
			ans = (ans*x)%m;
			n--;
		}
    }
	return (int)ans % m;
}