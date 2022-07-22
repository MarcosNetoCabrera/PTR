

typedef double (*PtrFunction)(double input);
double integral_trapezio(double delta,double limit_inferior, double limit_superior, PtrFunction funcao);
double integral_simpson(double delta, double limit_inferior, double limit_superior, PtrFunction funcao);