#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    float re;
    float im;
    float mod;
    float arg;
} Complexe;


void calcul_module(Complexe *c){
    printf("%f %f\n", c->re, c->im);
    printf("%f\n", sqrt(pow(c->re,2)+pow(c->im,2)));

    c->mod = sqrt(pow(c->re,2)+pow(c->im,2));
}

void calcul_arg(Complexe *c){
    c->arg = acos(c->re/c->mod);
}

Complexe somme_comp(Complexe c, Complexe v){
    Complexe somme;

    somme.re = c.re + v.re;
    somme.im = c.im + v.im;
    calcul_module(&somme);
    calcul_arg(&somme);

    return somme;
}

Complexe produit_comp(Complexe c, Complexe v){
    Complexe prod;
    prod.re = c.re * v.re;
    prod.im = c.im * v.im;

    calcul_module(&prod);
    calcul_arg(&prod);

    return prod;
}


int main(void){

    Complexe c;
    printf("entrer une partie reelle\n");
    scanf("%f", &c.re);

    printf("entrer une partie imaginaire\n");
    scanf("%f", &c.im);


    printf("%f %f\n", c.re, c.im);

    calcul_module(&c);
    calcul_arg(&c);


    printf("forme expo: %fe^i%f\n", c.mod, c.arg);
    return 0;
}
