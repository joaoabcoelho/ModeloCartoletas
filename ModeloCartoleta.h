
struct PlayerData {

  float pontos;
  float preco;
  float media;
  float ultima;
  int jogos;
  int desfalques;
  int rodadaAtual;
  int rodadaInicial;

};

float GetCartoletas(PlayerData player) {

  int   r  = player.rodadaAtual;
  int   r0 = player.rodadaInicial;
  int   d  = player.desfalques;

  float c  = player.preco;
  float a  = player.media;
  float g  = player.jogos;
  float u  = player.ultima;
  float p  = player.pontos;

  float a0 = 0;
  if(g>1) a0 = (a*g - u)/(g - 1);

  int dr = r;
  if(r0>1) dr = r - r0;

  if(g==0) d = dr - 1;
  if(d<0)  d = 0;
    
  float cr = 0; 
  float pr = 0; 
  float ur = 0; 

  if(dr>0){
    cr = c / dr;
    pr = p / dr;
    ur = u / dr;
  }
  
  float cdr = cr * d;
  float udr = ur * d;
  
  float var = 0;
  
  switch(dr){

    case  1:
      if( r0==1         ){ var = 0.6890*p - 0.3110*c; break; }
      if( r0>=2         ){ var = 0.4188*p - 0.2125*c; break; }

    case  2:
      if( r0==1 && d==1 ){ var = 0.4221*p - 0.2964*c; break; }
      if( r0>=2 && d==1 ){ var = 0.3589*p - 0.2272*c; break; }
      if( r0==1 && d==0 ){ var = 0.4221*p - 0.2964*c + 0.2813*u; break; }
      if( r0>=2 && d==0 ){ var = 0.3551*p - 0.1137*c - 0.0284*u; break; }

    case  3:
      if( r0==1 && d>=1 ){ var = 0.3301*p - 0.2930*c + 0.1882*u; break; }
      if( r0==1 && d==0 ){ var = 0.3299*p - 0.1440*c - 0.0237*u + 0.0471*a0; break; }
      if( r0>=2         ){ var = 0.2975*p - 0.0764*c - 0.0861*u + 0.0007*a0 - 0.2553*cdr + 0.2943*udr; break; }

    case  4:
      if( r0==1 && d>=2 ){ var = 0.2939*p - 0.2654*c + 0.1469*u; break; }
      if( r0==1 && d==1 ){ var = 0.2940*p - 0.1621*c + 0.0001*u + 0.0490*a0; break; }
      if( r0==1 && d==0 ){ var = 0.2936*p - 0.0564*c - 0.0827*u + 0.0222*a0; break; }
      if( r0>=2         ){ var = 0.2762*p - 0.0568*c - 0.1088*u + 0.0083*a0 - 0.2462*cdr + 0.2157*udr; break; }

    default:
      if( r0==1         ){ var = 0.1580*p + 0.0040*c - 0.1588*u + 0.0064*a0 - 0.2358*cdr + 0.1865*udr + 0.5140*pr - 0.3134*cr + 0.2803*ur; break; }
      if( r0>=2         ){ var = 0.1608*p - 0.0004*c - 0.1599*u + 0.0047*a0 - 0.2240*cdr + 0.1737*udr + 0.4748*pr - 0.2198*cr + 0.2322*ur; break; }

  }

  if(c + var < 0.7) var = 0.7 - c;

  return var;
    
}

