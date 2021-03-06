#include "gfinputset_receiver_key1.h"
#include <stdlib.h>


gfinputset_receiver_key1 *gfinputset_receiver_key1_new(void) { 
	return (gfinputset_receiver_key1 *) malloc(sizeof(gfinputset_receiver_key1));
}

void gfinputset_receiver_key1_init(gfinputset_receiver_key1 *g) {

}

void gfinputset_receiver_key1_finish(gfinputset_receiver_key1 *g){

}

void gfinputset_receiver_key1_destroy(gfinputset_receiver_key1 *g){
	free(g);
	g=NULL;
}

void gfinputset_receiver_key1_receive(gfinputset_receiver_key1 *g, gfinputset *is, gfinputset *pass) {
  //Receive input from key board and store on inputset is
  //  is->keys[0]=0;

  while( SDL_PollEvent( &(g->event) ) ){
    printf("event \t");
    if (g->event.type==SDL_KEYDOWN) {
    printf("keydown\n");
      switch(((SDL_KeyboardEvent *)(&(g->event)))->keysym.sym){
	//is
      case SDLK_h:
	is->keys[0] |= 2;
	break;
      case SDLK_j:
	is->keys[0] |= 4;
	break;
      case SDLK_k:
	is->keys[0] |= 8;
	break;
      case SDLK_u:
	is->keys[0] |= 16;
	break;
      case SDLK_q:
	is->keys[0] |= 32;
	break;
      case SDLK_w:
	is->keys[0] |= 64;
	break;	
      case SDLK_e:
	is->keys[0] |= 128;
	break;	
      case SDLK_a:
	is->keys[0] |= 256;
	break;	
      case SDLK_s:
	is->keys[0] |= 512;
	break;	
      case SDLK_d:
	is->keys[0] |= 1024;
	break;	
	//pass
      case SDLK_LEFT:
      case SDLK_4:
	pass->keys[0] |= 2;
	break;	
      case SDLK_DOWN:
      case SDLK_5:
	pass->keys[0] |= 4;
	break;	
      case SDLK_RIGHT:
      case SDLK_6:
	pass->keys[0] |= 8;
	break;	
      case SDLK_UP:
      case SDLK_8:
	pass->keys[0] |= 16;
	break;
      case SDLK_INSERT:
	pass->keys[0] |= 32;
	break;
      case SDLK_HOME:
	pass->keys[0] |= 64;
	break;
      case SDLK_PAGEUP:
	pass->keys[0] |= 128;
	break;
      case SDLK_DELETE:
	pass->keys[0] |= 256;
	break;
      case SDLK_END:
	pass->keys[0] |= 512;
	break;
      case SDLK_PAGEDOWN:
	pass->keys[0] |= 1024;
	break;
	//Quit
      case SDLK_ESCAPE:
	is->keys[0] |= 1;
	break;		
      default:
	break;
      }      
  } else if (g->event.type==SDL_KEYUP) {    
    printf("keyup \n");
      switch(((SDL_KeyboardEvent *)(&(g->event)))->keysym.sym){
	//is
      case SDLK_h:
	is->keys[0] ^= 2;
	break;	
      case SDLK_j:
	is->keys[0] ^= 4;
	break;	
      case SDLK_k:
	is->keys[0] ^= 8;
	break;	
      case SDLK_u:
	is->keys[0] ^= 16;
	break;	
      case SDLK_q:
	is->keys[0] ^= 32;
	break;	
      case SDLK_w:
	is->keys[0] ^= 64;
	break;	
      case SDLK_e:
	is->keys[0] ^= 128;
	break;	
      case SDLK_a:
	is->keys[0] ^= 256;
	break;	
      case SDLK_s:
	is->keys[0] ^= 512;
	break;	
      case SDLK_d:
	is->keys[0] ^= 1024;
	break;	
	//pass
      case SDLK_LEFT:
      case SDLK_4:
	pass->keys[0] ^= 2;
	break;	
      case SDLK_DOWN:
      case SDLK_5:
	pass->keys[0] ^= 4;
	break;	
      case SDLK_RIGHT:
      case SDLK_6:
	pass->keys[0] ^= 8;
	break;	
      case SDLK_UP:
      case SDLK_8:
	pass->keys[0] ^= 16;
	break;	
      case SDLK_INSERT:
	pass->keys[0] ^= 32;
	break;	
      case SDLK_HOME:
	pass->keys[0] ^= 64;
	break;	
      case SDLK_PAGEUP:
	pass->keys[0] ^= 128;
	break;	
      case SDLK_DELETE:
	pass->keys[0] ^= 256;
	break;	
      case SDLK_END:
	pass->keys[0] ^= 512;
	break;	
      case SDLK_PAGEDOWN:
	pass->keys[0] ^= 1024;
	break;
	//Quit
      case SDLK_ESCAPE:
	is->keys[0] |= 1;
	break;		
      default:
	break;
      }      
    } else if (g->event.type==SDL_QUIT) {
      is->keys[0] |= 1;
    }   
    printf("inputset received = (p1) %d  (p2) %d\n", is->keys[0], pass->keys[0]);
  }
}
