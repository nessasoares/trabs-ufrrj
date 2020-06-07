#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include <string.h>
#include <time.h>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#define ACTION_ALTURA 700
#define ACTION_LARGURA 1000
#define SPRITE_SIZE 81
#define OUTSIDE_ALTURA 720
#define OUTSIDE_LARGURA 1020
#define NUMERO_ASTEROIDS 4
#define RAIO_SIZE 14
#define MAX_ARRAY 100
#define MAX_NOME 12

#define FPS 20
int selection = 1;
//SDL SURFACE
int channel;

	TTF_Font* font = NULL;
	
	FILE * p_arquivo;
	SDL_Surface *background = NULL;
	SDL_Surface *recordscreen = NULL;
	SDL_Surface* inst = NULL;
	SDL_Surface *screen = NULL;
	SDL_Surface *image2 = NULL;
	SDL_Surface *meteoroImage1 = NULL;
	SDL_Surface *meteoroImage2 = NULL;
	SDL_Surface *meteoroImage3 = NULL;
	SDL_Surface *tiroImage = NULL;
	SDL_Surface *loki = NULL;
	SDL_Surface *explosao = NULL; 
	SDL_Surface *vida = NULL;
	Mix_Chunk *sound = NULL;

  	int running=1;
    int posicao=0;
    int instrucao = 0;
    int i, opcao_menu =1, running2 =1;
    int jogo_rodando = 0;
	SDL_Surface *perso = NULL, *fond = NULL,*fond1=NULL,*fond2=NULL,*fond3=NULL,*fond4=NULL,*fond5 = NULL;
	SDL_Rect posFond,posFond2,posFond3,posFond1,posFond4,posFond5;
	SDL_Event event;
  	int altura, largura;
  	char pontsrec[100];

  	int velocity = 1;
  	int record_screen = 0;
  	int andarpressionado = 0;
  	int desacelerar = 0;
  	int direcao=0;
  	SDL_Rect srcExplosao;
  	int vidas = 3;
  	int martelos = 2;
  	SDL_Rect srcVidas, dstVidas[3], dstVidasInicial;
  	int pontos = 0;
  	char pontos_str[11] = "0";
  	int name_typed = 0;
  	int typingname = 0;
  	int initials = 0;

	int audio_rate = 22050;					
 	Uint16 audio_format = AUDIO_S16SYS; 	
 	int audio_channels = 2;					
 	int audio_buffers = 4096;


 //STRUCTS
  	typedef struct
{
    char nome[10];
    int pontuacao;

} RECORDE;

typedef struct
{
    RECORDE vetor[10];
    int n;

} ARRAY;


  //STRUCT DO THOR
 typedef struct {
	
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Rect inicial;
	int direcao;
}JOGADOR_;

//STRUCT DO RAIO
typedef struct  {

	SDL_Rect src;
	SDL_Rect dst;
	int direcao;
	SDL_Rect inicial;
	int ativo;
}TIRO_;


//STRUCT DO METEORO NIVEL 3
typedef struct {
	
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Rect inicial;
	int ativo;
	int nivel;

} METEORO3_;

//STRUCT DO METEORO NIVEL 2
typedef struct {
	
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Rect inicial;
	METEORO3_ meteoro3[2];
	int ativo;
	int nivel;
} METEORO2_;

//STRUCT DO METEORO NIVEL 1
typedef struct {
	
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Rect inicial;
	int ativo;
	int direcao;
	int nivel;
	METEORO2_ meteoro2[2];
		} METEORO_;

   
//DECLARAR STRUCTS
JOGADOR_ player;
METEORO_ meteoro1 [4];
TIRO_ tiro;



RECORDE record;
ARRAY array, arraynew;

void insere(ARRAY *array, RECORDE recorde);
	    
void remove_posicao(ARRAY *array, int posicao);

void sort(ARRAY *array);

void bubble_sort(RECORDE[], int);

void MANAGER_FILE()
{
    p_arquivo = fopen("recordes.bin", "rb");
    
    if(fopen("recordes.bin", "rb") != NULL)
    {
    fread(&array, sizeof(ARRAY), 1, p_arquivo);
    insere(&array, record);
    arraynew = array;
    }

    else{
      array.n = 0;
    }
}

void desenha_texto(char* texto, SDL_Surface* dst, int x, int y) { 
	SDL_Color branco = {255, 255, 255};
	 
	SDL_Surface* pontuacao = TTF_RenderText_Blended(font, texto, branco);
	 SDL_Rect dst_rect = {x, y, 0, 0};

	 SDL_BlitSurface(pontuacao, NULL, dst, &dst_rect);
	 SDL_FreeSurface(pontuacao);

	 
}

void bubble_sort(RECORDE list[], int n)
{
  int i, j;
    RECORDE swap;

  for(i = 0 ; i < ( n - 1 ); i++)
  {
    for(j = 0 ; j < n - i - 1; j++)
    {
      if(list[j].pontuacao < list[j+1].pontuacao)
      { 
        swap = list[j];
        list[j] = list[j+1];
        list[j+1] = swap;
      }
    }
  }
}

void sort(ARRAY *array)
{
  bubble_sort(array->vetor, array->n);
}

RECORDE elemento(ARRAY *array, int posicao)
{
  return array->vetor[posicao];
}

int tamanho(ARRAY *array)
{
  return array->n;
}

void remove_posicao(ARRAY *array, int posicao)
{
  if(tamanho(array) == 0)
  {
    return;
  }
  else if(tamanho(array) == 1)
  {
    array->n -= 1;
    return;
  }
  else
  {
    array->n -= 1;
    array->vetor[posicao] = array->vetor[tamanho(array)];
  }
    
    sort(array);
}

void insere(ARRAY *array, RECORDE recorde)
{
    if(tamanho(array) < MAX_ARRAY)
    {
        array->vetor[tamanho(array)] = recorde;
        array->n += 1;
    }
    else
    {
        RECORDE menor_recorde;
        menor_recorde = elemento(array, MAX_ARRAY - 1);
        
        if(menor_recorde.pontuacao >= recorde.pontuacao)
        {
            return;
        }
        else
        {
            remove_posicao(array, MAX_ARRAY - 1);
            insere(array, recorde);
            return;
        }
    }
    
    sort(array);
}

void imprime(ARRAY *array)
{
  int i;

    printf("------------------------------\n");
  printf("Recordes:\n");

  RECORDE recorde;

   //int x = 50, y = 50;

  for(i = 0; i < tamanho(array); i++)
  {
        recorde = elemento(array, i);
        printf("%d - %d :: %s \n", i+1, recorde.pontuacao, recorde.nome);
  }

  printf("------------------------------\n");
}

void reverse (char string[]){
	 int i, j;
	 char aux;
	 for (i = 0, j = strlen(string)-1; i<j; i++, j--){
 		aux = string[i]; 
 		string[i] = string[j];
 		string[j] = aux;
 }
}


void itoa(int numero, char string[]){
	int i, sign; 
	
	if ((sign = numero) < 0) 
		numero = -numero;
	
	i = 0; 
	
	do{ 
 		string[i++] = numero % 10 + '0';
    	}while ((numero /= 10) > 0);

	if (sign < 0)
		string[i] = '-';

	 string[i] = '\0';
	 reverse(string);
}

void atualizaPontos(int novo_ponto){
	
	pontos += novo_ponto;
	itoa(pontos,pontos_str);
}

void explosion(SDL_Rect posicao){
	int i, j;

		for(j=0; j<44; j++){
	
				srcExplosao.x += 72;
				SDL_BlitSurface(explosao, &srcExplosao, screen, &posicao);
			
		
}
	srcExplosao.x = 0;
}


void blitarVidas(){
	SDL_BlitSurface(vida, &srcVidas, screen, &dstVidas[0]);
	SDL_BlitSurface(vida, &srcVidas, screen, &dstVidas[1]);
	SDL_BlitSurface(vida, &srcVidas, screen, &dstVidas[2]);
}
void verificaLimites(){

	if(player.dst.x> ACTION_LARGURA ){
		player.dst.x = 50;
		}
		if(player.dst.x< 0){
			player.dst.x = ACTION_LARGURA - 50;
		}

		if(player.dst.y> ACTION_ALTURA ){
			player.dst.y = 50;
		}
		 if(player.dst.y< 0){
			player.dst.y = ACTION_ALTURA - 50;
		}
	}
	



void drawSprite( SDL_Surface* screenSurface, JOGADOR_  player, int width, int height)
{
   /*SDL_Rect srcRect;
   srcRect.x = srcX;
   srcRect.y = srcY;
   srcRect.w = width;
   srcRect.h = height;

   SDL_Rect dstRect;
   dstRect.x = dstX; //sprite
   dstRect.y = dstY; //sprite
   dstRect.w = width;
   dstRect.h = height;
	*/

   player.src.h = height;
   player.src.w = width;

    player.dst.h = height;
   player.dst.w = width;

   verificaLimites();

   SDL_BlitSurface(image2, &player.src, screenSurface, &player.dst);
}


void drawTiro(int direcao){
	SDL_Rect dst;
	SDL_Rect srcRect;
	int contador = 0;
	switch(direcao){
		case 0: 
		
			tiro.dst.y -= 30;
			break;

		case 1:
		
			tiro.dst.x += 15;
		
			tiro.dst.y -= 15;
			break;

		case 2:

			tiro.dst.x += 30;
			break;

		case 3:
	
			tiro.dst.x += 15;
			
			tiro.dst.y += 15;
			break;

		case 4:
			
			tiro.dst.y += 30;
			break;

		case 5:
			 
			tiro.dst.x -= 15;
		
			tiro.dst.y += 15;
			break;

		case 6:
		
			tiro.dst.x -=  30;
			break;
		case 7:	
		
			tiro.dst.x-= 15;
		
			tiro.dst.y -= 15;
		}	

			
			
   tiro.src.x = posicaoImagem(tiro.direcao, RAIO_SIZE);
   tiro.src.y = 0;
   tiro.src.w = RAIO_SIZE;
   tiro.src.h = RAIO_SIZE;



	SDL_BlitSurface(tiroImage, &tiro.src, screen, &tiro.dst);


}




void CONTROL_MENU()
{

    	
	
    
        SDL_WaitEvent(&event);
            switch(event.type){

                case SDL_QUIT:
                exit(1);
                break;

                case SDL_KEYDOWN:
                     switch (event.key.keysym.sym){
                            case SDLK_UP:
                            selection -= 1;
                            break;

                            case SDLK_DOWN:
                            selection+=1;
                            
                            break;

                            case SDLK_ESCAPE:
                            //recorde tbm serve
                            if(instrucao == 1)
                            {
                            	instrucao = 0;
                            }

                            else if(record_screen == 1)
                            {
                            	record_screen = 0;
                            }

                            else{
                            exit(1);
                            }

                            break;

                            case SDLK_RETURN:
                            //func(selection);

                            if(selection == 1)
                            {
                            	jogo_rodando = 1;

                            	//running = 0;
                            }

                            if(selection == 2)
                            {

                            	instrucao = 1;
                            }

                            if(selection == 3)
                            {
                            	record_screen = 1;
                            }
                            if(selection == 4)
                            {
                            	exit(1);
                            }

                            
                            break;
                        }
                    break;    
                 }           
                     
               if(selection<1)
               {
                selection = 4;
               }

               if(selection>4)
               {
                selection = 1;
               }
           

               if (selection==1){
                

               fond = IMG_Load ("jogar.png");
               SDL_BlitSurface(fond,NULL,screen,&posFond);

               //SDL_Flip(screen);
             

               }

               if (selection==2){
                
                
                fond = IMG_Load ("comojogar.png");
                inst = IMG_Load("comojogar1.png");
                sound = Mix_LoadWAV("applause.wav");
                
                  SDL_BlitSurface(fond,NULL,screen,&posFond);
                 
                //SDL_Flip(screen);
             
            }
             if (selection==3){
               
                 
                 fond = IMG_Load ("records.png");
                 recordscreen = IMG_Load("records1.png");
                  
                  SDL_BlitSurface(fond,NULL,screen,&posFond);
                 
                  // SDL_Flip(screen);
             
               }
                 if (selection==4){
                
                 fond= IMG_Load ("sair.png");
                 
                   SDL_BlitSurface(fond,NULL,screen,&posFond);
                   //SDL_Flip(screen);
             
               }      
        
    }
    
  


  /*  void game_over(SDL_Surface *screen){

	SDL_Surface *fond5 = NULL;
	SDL_Event event;
	//int jogo_rodando = 1;
	fond5 = IMG_Load("recordes.jpg");
	posFond5.x = 20;
	posFond5.y = 20;
	SDL_BlitSurface(fond5,NULL,screen,&posFond5);
	SDL_Flip(screen);
    
    /*while(running != 0){
    	SDL_WaitEvent(&event);
    	if (event.key.keysym.sym==SDLK_ESCAPE){
    		running = 0;
    		//exit(0);
    	}
    	jogo_rodando = 0;
    	SDL_WaitEvent(&event);
            switch(event.type){

                case SDL_QUIT:
                running =0;

                break;

                case SDL_KEYDOWN:
                     switch (event.key.keysym.sym){

                            case SDLK_SPACE:
                           
                           	     exit(0);
                           
                            break;
                     }
                     break;
                }            
    }*/
	//escrever_recorde();
   /* SDL_FreeSurface(fond5);
    
}*/
  

void coordSprites(int direcao){

	

	switch(direcao){
		case 0: 
			player.dst.y -= velocity;
			break;

		case 1:
			player.dst.x += velocity;
			player.dst.y -= velocity;
			break;

		case 2:
			player.dst.x += velocity;
			break;

		case 3:
			player.dst.x += velocity;
			player.dst.y += velocity;
			break;

		case 4:
			player.dst.y += velocity;
			break;

		case 5:
			player.dst.x -=velocity;
			player.dst.y +=velocity;
			break;

		case 6:
			player.dst.x -= velocity;
			break;
		case 7:	
			player.dst.x -=velocity;
			player.dst.y -= velocity;
			break;


	}

	
}

SDL_Rect direcaoAsteroids(SDL_Rect meteoro, int t){
	
	SDL_Rect met;

	met = meteoro;

		if(t>3){
			t=0;
		}
		switch(t){

		case 0:
			met.x += 1.5;
			met.y -= 1.5;
			break;

		case 1:
			met.x += 1.5;
			met.y += 1.5;
			break;

		
		case 2:
			met.x -=1.5;
			met.y +=1.5;
			break;

		
		case 3:	
			met.x -=1.5;
			met.y -= 1.5;
			break;
		
	}

	if ( met.x > OUTSIDE_LARGURA ) {
				met.x = 10;
			    }
			  else if  (met.x < 0 ){
			  	met.x = OUTSIDE_LARGURA - 10;

			  } 
			  else if(met.y > OUTSIDE_ALTURA){
			  			met.y = 10;
			  } 
			  else if (met.y< 0)  {	
				met.y = OUTSIDE_ALTURA - 10;
			}

	return met;


}


int posicaoImagem(int direcao, int tamanho){
	int posicao;

	posicao = direcao * tamanho;
		if(posicao< 0) {
 				posicao = 680;
 			}
 			else if(posicao>680){
 				posicao = 0;
 			} 
	return posicao;
}

int startTiro(TIRO_ tiro, int direcao){
        
                
                drawTiro(direcao);
                  
                 if((tiro.dst.x >= OUTSIDE_LARGURA ) || (tiro.dst.x <= 0 ) || (tiro.dst.y >= OUTSIDE_ALTURA) || (tiro.dst.y<= 0)){
                    tiro.direcao = -1;
                 
                 }
                 else{
                 	tiro.direcao = tiro.direcao;
                 }
                

            return tiro.direcao;
}


void asteroidsOcultos(){
	int i, j, k;
	for(i=0; i<4; i++){
		
		for(j=0; j<2; j++){
			if(meteoro1[i].meteoro2[j].ativo == 0){
				meteoro1[i].meteoro2[j].dst = meteoro1[i].dst;
			}
		for(k=0; k<2; k++){
			if(meteoro1[i].meteoro2[j].meteoro3[k].ativo == 0){
			meteoro1[i].meteoro2[j].meteoro3[k].dst = meteoro1[i].meteoro2[j].dst;
			}
		}
		}
	}	
}


void posicaoAsteroide(){

		meteoro1[0].dst.x = meteoro1[0].dst.x + 2;
		meteoro1[0].dst.y = meteoro1[0].dst.y + 1;
		
		meteoro1[1].dst.x = meteoro1[1].dst.x - 0.25;
		meteoro1[1].dst.y = meteoro1[1].dst.y + 1;

		meteoro1[2].dst.x = meteoro1[2].dst.x - 1.5;
		meteoro1[2].dst.y = meteoro1[2].dst.y - 1;

		meteoro1[3].dst.x = meteoro1[3].dst.x + 1.2;
		meteoro1[3].dst.y = meteoro1[3].dst.y - 1;


		
					
			asteroidsOcultos();				
}


void blittarAsteroids(){
	int i, j, k;
	for(i=0; i<4; i++){

		if(meteoro1[i].ativo == 1){
			meteoro1[i].dst = direcaoAsteroids(meteoro1[i].dst, -1);
			SDL_BlitSurface(meteoroImage1, &meteoro1[i].src, screen, &meteoro1[i].dst);
		}
		for(j=0; j<2; j++){
			if(meteoro1[i].meteoro2[j].ativo == 1){

				meteoro1[i].meteoro2[j].dst = direcaoAsteroids(meteoro1[i].meteoro2[j].dst, j+i);
			SDL_BlitSurface(meteoroImage2, &meteoro1[i].meteoro2[j].src, screen, &meteoro1[i].meteoro2[j].dst);
			}
		for(k=0; k<2; k++){
			if(meteoro1[i].meteoro2[j].meteoro3[k].ativo == 1){
				meteoro1[i].meteoro2[j].meteoro3[k].dst = direcaoAsteroids(meteoro1[i].meteoro2[j].meteoro3[k].dst, k+j);
			SDL_BlitSurface(meteoroImage3, &meteoro1[i].meteoro2[j].meteoro3[k].src, screen, &meteoro1[i].meteoro2[j].meteoro3[k].dst);
			}
		}
		}
	}	
}




int checkColisaoThor(SDL_Rect A, SDL_Rect B, int h, int w){
		int esquerda1, esquerda2, direita1, direita2, cima1, cima2, baixo1, baixo2;
		int colisao;

	
	esquerda1 = A.x; 
	direita1 = A.x + w;
	cima1 = A.y;
	baixo1 = A.y + h;


	
	esquerda2 = B.x + 20;
	direita2 = B.x + (w -20);
	cima2 = B.y +20;

	baixo2 = B.y + (h - 20);


	if((baixo1 <= cima2) || (cima1 >= baixo2) || (direita1 <= esquerda2) || (esquerda1 >= direita2)){
		colisao = 0;
	}
	/*else if(cima1 >= baixo2){
		colisao = 0;

	}
	else if(direita1 <= esquerda2){
		colisao = 0;
	}
	else if(esquerda1 >= direita2){
		colisao = 0;
	}	*/
	else{colisao =1;}
	return colisao;
	}

int checkColisaoRaio(SDL_Rect tiro, SDL_Rect meteoro, int alt, int larg ){
	int colisao = 0;

	if((tiro.y >= meteoro.y + alt) || (tiro.x >= meteoro.x + larg) || (tiro.y + tiro.h <= meteoro.y ) || (tiro.x + tiro.w <= meteoro.x )){
		colisao = 0;
		
	}
	else{

	colisao = 1;
	}

	return colisao;
}


void asteroidsAtivos(){
	int i, j, k;
		for(i=0; i<4; i++){
			meteoro1[i].ativo = 1;

			for(j=0; j<2; j++){

				meteoro1[i].meteoro2[j].ativo = 0;

				for(k=0; k<2; k++){
					meteoro1[i].meteoro2[j].meteoro3[k].ativo = 0;
				}
			}
		}


}



void colisao(){
	int i, j, k, thor=0, raio;
	  
	

	//thor = checkCollisionThor(player, meteoro[i]);

	for(i=0; i<4; i++){
		if((checkColisaoThor(player.dst, meteoro1[i].dst, 100, 95) == 1)&&(checkColisaoThor( meteoro1[i].dst,player.dst, 100, 95) == 1)) {
			if(meteoro1[i].ativo != 0){
			thor = 1;
			}
		}

		if((checkColisaoRaio(tiro.dst, meteoro1[i].dst, 100, 95) != 0)&&(checkColisaoRaio( meteoro1[i].dst,tiro.dst, 100, 95) != 0)){
				if(meteoro1[i].ativo != 0){
					meteoro1[i].ativo = 0;
					explosion(meteoro1[i].dst);
					meteoro1[i].meteoro2[0].ativo = 1;
					meteoro1[i].meteoro2[1].ativo = 1;
					tiro.dst = tiro.inicial;
					atualizaPontos(10);
				}


		}
		else {

			for(j=0; j<2; j++){	
				if((checkColisaoThor(player.dst, meteoro1[i].meteoro2[j].dst, 95, 75) == 1)&&(checkColisaoThor( meteoro1[i].meteoro2[j].dst,player.dst, 95, 75) == 1)){
					if(meteoro1[i].meteoro2[j].ativo != 0){
					thor = 2;
					}	
				}
		
				if((checkColisaoRaio(tiro.dst, meteoro1[i].meteoro2[j].dst, 95, 75) != 0)&&(checkColisaoRaio(meteoro1[i].meteoro2[j].dst,tiro.dst, 95, 75) != 0)){
					if(meteoro1[i].meteoro2[j].ativo != 0){
						meteoro1[i].meteoro2[j].ativo = 0;
							explosion(meteoro1[i].meteoro2[j].dst);
						meteoro1[i].meteoro2[j].meteoro3[0].ativo = 1;
						meteoro1[i].meteoro2[j].meteoro3[1].ativo = 1;
						tiro.dst = tiro.inicial;
						atualizaPontos(25);
				
					}			
				}

				else{
					for(k=0; k<2; k++){
						if((checkColisaoThor(player.dst, meteoro1[i].meteoro2[j].meteoro3[k].dst, 50, 45) == 1)&&(checkColisaoThor( meteoro1[i].meteoro2[j].meteoro3[k].dst,player.dst, 50, 45) == 1)){
							if(meteoro1[i].meteoro2[j].meteoro3[k].ativo != 0){
							thor = 3;
							}
						}
		
						if((checkColisaoRaio(tiro.dst, meteoro1[i].meteoro2[j].meteoro3[k].dst, 50, 45) != 0) &&(checkColisaoRaio( meteoro1[i].meteoro2[j].meteoro3[k].dst,tiro.dst, 50, 45)!= 0)){
							if(meteoro1[i].meteoro2[j].meteoro3[k].ativo != 0){
								meteoro1[i].meteoro2[j].meteoro3[k].ativo = 0;
									explosion(meteoro1[i].meteoro2[j].meteoro3[k].dst);

							}
							if((meteoro1[i].meteoro2[j].meteoro3[0].ativo == 0) && (meteoro1[i].meteoro2[j].meteoro3[1].ativo == 0)){
								meteoro1[i].ativo = 1; 
							}
							atualizaPontos(50);
							tiro.dst = tiro.inicial;
												
			
						}
					}
				}
			}

		}	
	}

	if(thor != 0){
		velocity = 0;
		player.dst = player.inicial;
		
		dstVidas[martelos] = dstVidasInicial;
		martelos--;
	}

}



void Init(){
	
	int i, k, j; 
	SDL_Surface *IMG_Load(const char *file);
	Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) ;

    SDL_Init (SDL_INIT_EVERYTHING);
    TTF_Init();
    
    SDL_Event event;

    //ABRE A TELA
    screen = SDL_SetVideoMode(ACTION_LARGURA, ACTION_ALTURA, 32, SDL_SWSURFACE);

    //NOME
   	SDL_WM_SetCaption("asTHORoids ", NULL);
   
    sound = Mix_LoadWAV("applause.wav");
    channel = Mix_PlayChannel(-1, sound, 0);
   	//LOAD IMAGENS
	background = IMG_Load("space.png"); //BACKGROUND
        
   image2 = IMG_Load("spriteThor.png"); //THOR
   tiroImage= IMG_Load("raio_tira.png"); //RAIO
   loki = IMG_Load("Loki_1.png"); //LOKI
   explosao = IMG_Load ("explosao72.png"); //explosao
   vida = IMG_Load("life.png");
    
    //inicializando os meteoros nivel 1

    	meteoroImage1= IMG_Load("asteroid_1.png");


	
    	meteoroImage2= IMG_Load("asteroid_2.png");
    	
	
    	meteoroImage3 = IMG_Load("asteroid_3.png");
  		font = TTF_OpenFont("ARCADE_N.TTF",20);
//POSIÇÕES INICIAIS
    
//thor
	 largura = 80;
   altura = 80;

//explosao
   srcExplosao.h = 72;
   srcExplosao.w = 72;
   srcExplosao.y = 0;
   srcExplosao.x = 0;


   //vidas
   
   srcVidas.x = 0;
   srcVidas.y =0;
   srcVidas.h = 54;
   srcVidas.w = 54;


	dstVidas[0].x = 70;
	dstVidas[0].y =20;
	dstVidas[1].x = 134;
	dstVidas[1].y =20;
	dstVidas[2].x = 198;
	dstVidas[2].y =20;

	dstVidasInicial.x = 1000;
	dstVidasInicial.y = 1000; 


	//asteroids
	//posicao 0
	meteoro1[0].inicial.x = -10; 
	meteoro1[0].inicial.y = -20;

	//posicao1
	meteoro1[1].inicial.x = 800; 
	meteoro1[1].inicial.y = 100;

	//posicao2
	meteoro1[2].inicial.x = 900; 
	meteoro1[2].inicial.y = 50;

	//posicao3
	meteoro1[3].inicial.x = 100; 
	meteoro1[3].inicial.y = 350;


		for(i=0; i<4; i++){
		meteoro1[i].dst = meteoro1[i].inicial;
		meteoro1[i].src.x = 3;
 		meteoro1[i].src.y = 3;
 		meteoro1[i].src.h = 99;
 		meteoro1[i].src.w = 94;
 		meteoro1[i].dst.h = 110;
	 	meteoro1[i].dst.w = 100;
	 	meteoro1[i].ativo = 1;
	 	meteoro1[i].nivel= 1;

	 	for(j=0; j<2; j++){
		
		meteoro1[i].meteoro2[j].src.x = 3;
 		meteoro1[i].meteoro2[j].src.y = 3;
 		meteoro1[i].meteoro2[j].src.h = 91;
 		meteoro1[i].meteoro2[j].src.w = 72;
 		meteoro1[i].meteoro2[j].dst.h = 100;
	 	meteoro1[i].meteoro2[j].dst.w = 85;
	 	meteoro1[i].meteoro2[j].ativo = 0;
	 	meteoro1[i].meteoro2[j].nivel = 2;

	 	for(k=0; k<2; k++){
	
		meteoro1[i].meteoro2[j].meteoro3[k].src.x = 3;
 		meteoro1[i].meteoro2[j].meteoro3[k].src.y = 3;
 		meteoro1[i].meteoro2[j].meteoro3[k].src.h = 45;
 		meteoro1[i].meteoro2[j].meteoro3[k].src.w = 39;
 		meteoro1[i].meteoro2[j].meteoro3[k].dst.h =60;
	 	meteoro1[i].meteoro2[j].meteoro3[k].dst.w = 55;
	 	meteoro1[i].meteoro2[j].meteoro3[k].ativo= 0;
	 	meteoro1[i].meteoro2[j].meteoro3[k].nivel= 3;
		}

		
		}

		
		}

//tiro

		 tiro.inicial.x =-100;
  		 tiro.inicial.y =-100;

}

void DIGITAR_NOME()
{

       fclose(p_arquivo);
       p_arquivo = fopen("recordes.bin", "wb");
       

       //draw_text("GAME OVER!", fonte, screen, 350, 0, 0, 0, 255);
       desenha_texto("GAME OVER!", screen, 350, 100);

       desenha_texto("Digite seu nome : ", screen, 10, 300);
       
       desenha_texto(record.nome, screen, 400, 300);
       
       
    
}

void RECORDES()
{

    int i, x= 150, y=200;
    
   


    if(fopen("recordes.bin", "rb") != NULL)
    {
      fread(&arraynew, sizeof(ARRAY), 1, p_arquivo);
            for(i=0; i<10; i++)
           {
            

            if(arraynew.vetor[i].pontuacao != 0)
            {
            //itoa((i+1), pontsrec);
            //desenha_texto(pontsrec, screen, 0, y);
            //desenha_texto("- ", screen, 18, y);

            desenha_texto(arraynew.vetor[i].nome, screen, 50, y);
            itoa(arraynew.vetor[i].pontuacao, pontsrec );
            desenha_texto(pontsrec, screen, x+100, y);
            y+= 50;
            }

           /* if(arraynew.vetor[i].pontuacao == 0)
            {
              desenha_texto("Sem Recordes",screen, 50, y);
            }*/
          // atualizaPontos(0);
          // martelos = 2;
           //blitarVidas();    
           }

     }
 

 else{
       desenha_texto("No scores!",screen, x, 70);
            
     }

 y = 0;
        



    imprime(&arraynew);

    fclose(p_arquivo);
}


int main(int argc, char* argv[]){
 posFond.x = 0;
 posFond.y = 0;

 
 MANAGER_FILE();

int running=1;
int posicao=0;
int i;

Uint32 start;

tiro.direcao = -1;

player.direcao = 0;

//INICIALIZA VARIAVEIS DO THOR
player.src.x = 0;
player.src.y = 0;
 //player.src.w = SPRITE_SIZE;
// player.src.h = SPRITE_SIZE;
player.inicial.x =350;
player.inicial.y =350;
player.dst.x = player.inicial.x;
player.dst.y = player.inicial.y;
player.dst.h =80;
player.dst.w =80;

//INICIALIZA VARIAVEIS ASTEROID

for(i=0; i<NUMERO_ASTEROIDS; i++){
  
}
 
SDL_Event event;

	
	Init();
	


	     while(running == 1){
	     	;
	       	if(jogo_rodando == 1){

	       	start = SDL_GetTicks();

		
            
		
        if (SDL_PollEvent(&event)){
           if (event.type == SDL_QUIT) {
            running = 0;
           }
         }

		switch(event.type)
		{
			//close button clicked
			case SDL_QUIT:
				running = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					
					      break;
					case SDLK_LEFT:
					
						
						player.direcao -=1; 

						break;
					case SDLK_RIGHT:
					
						player.direcao += 1; 
                		break;
					case SDLK_UP:
						// movendo a nave para cima! 
                    
						andarpressionado = 1;
						//case SDLK_DOWN:
					
						//dstxy +=1 ;
						break;
					case SDLK_SPACE:

					   if(tiro.direcao != -1)
					   {
					   	tiro.direcao = tiro.direcao;
					   }

					   else
					   {
						tiro.direcao = player.direcao;

						tiro.dst.x = player.dst.x + (SPRITE_SIZE / 2);
						tiro.dst.y = player.dst.y + (SPRITE_SIZE / 2);
					}
						break;

						case SDLK_RETURN:

						if(typingname == 1)
                {
                  typingname = 0;
                  jogo_rodando = 0;
                  record.nome[initials] = '\0';
                  record.pontuacao = pontos;
                  vidas = 3;
                  martelos = 2;
                  insere(&array, record);
                  fwrite(&array, sizeof(ARRAY), 1, p_arquivo);
                  
                  fclose(p_arquivo);
                  p_arquivo = fopen("recordes.bin", "rb");
                  

                  int clear;

                  for(clear =0; clear<initials; clear++)
                  {
                  record.nome[clear] = ' ';
                  }

                  initials = 0;
                }
                   break;

				  while(name_typed == 0 && typingname == 1)
                {

                  if(initials < MAX_NOME)
                  {
                   case SDLK_a: record.nome[initials] = 'a';
                initials++; break;
            case SDLK_b: record.nome[initials] = 'b';
                initials++; break;
            case SDLK_c: record.nome[initials] = 'c';
                initials++; break;
            case SDLK_d: record.nome[initials] = 'd';
                initials++; break;
            case SDLK_e: record.nome[initials] = 'e';
                initials++; break;
            case SDLK_f: record.nome[initials] = 'f';
                initials++; break;
            case SDLK_g: record.nome[initials] = 'g';
                initials++; break;
            case SDLK_h: record.nome[initials] = 'h';
                initials++; break;
            case SDLK_i: record.nome[initials] = 'i';
                initials++; break;
            case SDLK_j: record.nome[initials] = 'j';
                initials++; break;
            case SDLK_k: record.nome[initials] = 'k';
                initials++; break;
            case SDLK_l: record.nome[initials] = 'l';
                initials++; break;
            case SDLK_m: record.nome[initials] = 'm';
                initials++; break;
            case SDLK_n: record.nome[initials] = 'n';
                initials++; break;
            case SDLK_o: record.nome[initials] = 'o';
                initials++; break;
            case SDLK_p: record.nome[initials] = 'p';
                initials++; break;
            case SDLK_q: record.nome[initials] = 'q';
                initials++; break;
            case SDLK_r: record.nome[initials] = 'r';
                initials++; break;
            case SDLK_s: record.nome[initials] = 's';
                initials++; break;
            case SDLK_t: record.nome[initials] = 't';
                initials++; break;
            case SDLK_u: record.nome[initials] = 'u';
                initials++; break;
            case SDLK_v: record.nome[initials] = 'v';
                initials++; break;
            case SDLK_w: record.nome[initials] = 'w';
                initials++; break;
            case SDLK_x: record.nome[initials] = 'x';
                initials++; break;
            case SDLK_y: record.nome[initials] = 'y';
                initials++; break;
            case SDLK_z: record.nome[initials] = 'z';
                initials++; break;
               }
           
                

                case SDLK_BACKSPACE:
                  
                 initials--;
                 record.nome[initials] = ' ';

                 if(initials < 0)
                 {
                  initials = 0;
                 }
                 break;

                 if(initials >= 13)
                 {
                  record.nome[12] = ' ';
                  initials = 11;
                 }

				
					
					}
					}
 

            

			if(player.direcao > 7 ) { 
				player.direcao = 0;
 			}
 			else if(player.direcao < 0) {
 				player.direcao = 7;
 			}

			player.src.x = posicaoImagem(player.direcao, SPRITE_SIZE);


 			break;

			case SDL_KEYUP: 

			switch(event.key.keysym.sym)
				{

					case SDLK_UP: andarpressionado = 0;
					              desacelerar = 1;
					  break;

					}

					break;
    
		}
		  if(desacelerar == 0)
       {
		   if(velocity<30)
		   {
		   	velocity += 1;
		   }

		   if(velocity == 30)
		   {
		   	velocity = velocity;
		   }
        }

          if(andarpressionado == 1)
            {
            	desacelerar = 0;
            	coordSprites(player.direcao);
            }

            if(desacelerar == 1)
            {
            	velocity -=0.5;
            	coordSprites(player.direcao);

            	if(velocity == 0)
            	{
            		desacelerar = 0;
            		velocity = 1;
            	}
            }

            


           SDL_BlitSurface(background, NULL, screen, NULL);
          
          char ponto_txt[10] = "Pontos:";
		   desenha_texto((strcat(ponto_txt,pontos_str)),screen,700,30);
          

            if(tiro.direcao != -1){
           	tiro.direcao = startTiro(tiro, tiro.direcao);
           }
           else if(tiro.direcao == -1){
           	tiro.dst.x = -300;
           	tiro.dst.y = -300;
           }

           

           drawSprite(screen, player, largura, altura); // variaveis do thor

           posicaoAsteroide();
           blittarAsteroids();
           blitarVidas();
           colisao();

           if(martelos < 0)
           {
           	typingname = 1;
           	DIGITAR_NOME();
           }
        
        	
        	
     }

        	         else{
               
               CONTROL_MENU();

               if(instrucao == 1)
               {
               	selection = 2;
               	SDL_BlitSurface(inst,0,screen,0);
               }

               if(record_screen == 1)
               {
               	selection = 3;

               	SDL_BlitSurface(recordscreen,0,screen,0);
               	RECORDES();
               }


       }

  if(1000/FPS >(SDL_GetTicks()-start))
          SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
       //SDL_Flip( screen);
       SDL_Flip( screen);
         }

          


//SDL_FreeSurface(fond);
Mix_FreeChunk(sound);
Mix_CloseAudio();
TTF_Quit();
SDL_Quit();

return 0;
}
