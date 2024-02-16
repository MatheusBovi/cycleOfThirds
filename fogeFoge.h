#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PILULA 'P'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

struct posicao {
    int x;
    int y;
};

typedef struct posicao POSICAO;

void liberamapa(MAPA* m);
void leiamapa(MAPA* m);
void alocarmapa(MAPA* m);
void imprimemapa(MAPA* m);
int encontramapa(MAPA* m, POSICAO* p, char c);
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);


int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino);
void fantasmas();
void move(char direcao);
int acabou();
int ehdirecao(char direcao);
int podeandar(MAPA* m, char personagem, int x, int y);
void explodepilula();
void explodepilula2(int x, int y, int somax, int somay, int qtd);
void imprimeparte(char desenho[4][7], int parte);
#endif

