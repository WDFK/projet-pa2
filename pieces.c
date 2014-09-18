#include pieces.h

pieces miseAZero (pieces S)
{
  for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
	{
	  S->tab0[i][j] = 0;
	  S->tab1[i][j] = 0;
	  S->tab2[i][j] = 0;
	  S->tab3[i][j] = 0;
	  S->tab4[i][j] = 0;
	  S->tab5[i][j] = 0;
	  S->tab6[i][j] = 0;
	  S->tab7[i][j] = 0;
	  S->tab8[i][j] = 0;
	  S->tab9[i][j] = 0;
	  S->tab10[i][j] = 0;
	  S->tab11[i][j] = 0;
	}
    }  
}
