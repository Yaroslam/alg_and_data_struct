double sum(double a, double b){
    return a+b;
}

double minus(double a, double b){
    return  a - b;
}

double mult(double a, double b){
    return a*b;
}

double divid(double a, double b){
    if(b == 0){
        return -1;
    }

    return a/b;
}

double pow(double a, unsigned long long b) {
    double res = 1.0;
    while(b != 0) {
        if((b & 1) != 0) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}