#include "gfrect.h"
#include <stdlib.h>


gfrect *gfrect_new(void) { 
	return (gfrect *) malloc(sizeof(gfrect));
}
void gfrect_init(gfrect *g) {

}

void gfrect_finish(gfrect *g){

}

void gfrect_destroy(gfrect *g){
	free(g); 
}

int  gfrect_collide(gfrect *g1, gfrect *g2) {
        return 0;
}