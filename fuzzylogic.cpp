#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////

//Initialise Fuzzy Rules

void initFuzzyRules(fuzzy_system_rec *fl) {

	const int
      no_of_xtheta_rules = 25;
   
   int i;

	// X vs Y
	
	for (i = 0;i < no_of_xtheta_rules;i++) {
       fl->rules[i].inp_index[0] = in_X;
       fl->rules[i].inp_index[1] = in_Y;
	}
	fl->rules[0].inp_fuzzy_set[0] = in_nl;
   fl->rules[0].inp_fuzzy_set[1] = in_pl;
	fl->rules[0].out_fuzzy_set = out_ns;
   fl->rules[1].inp_fuzzy_set[0] = in_ns;
	fl->rules[1].inp_fuzzy_set[1] = in_pl;
   fl->rules[1].out_fuzzy_set = out_ps;
	fl->rules[2].inp_fuzzy_set[0] = in_ze;
   fl->rules[2].inp_fuzzy_set[1] = in_pl;
	fl->rules[2].out_fuzzy_set = out_ps;
   fl->rules[3].inp_fuzzy_set[0] = in_ps;
	fl->rules[3].inp_fuzzy_set[1] = in_pl;
   fl->rules[3].out_fuzzy_set = out_pm;
	fl->rules[4].inp_fuzzy_set[0] = in_pl;
   fl->rules[4].inp_fuzzy_set[1] = in_pl;
	fl->rules[4].out_fuzzy_set = out_ps;
   
	fl->rules[5].inp_fuzzy_set[0] = in_nl;
   fl->rules[5].inp_fuzzy_set[1] = in_ps;
	fl->rules[5].out_fuzzy_set = out_ns;
   fl->rules[6].inp_fuzzy_set[0] = in_ns;
	fl->rules[6].inp_fuzzy_set[1] = in_ps;
   fl->rules[6].out_fuzzy_set = out_ns;
	fl->rules[7].inp_fuzzy_set[0] = in_ze;
   fl->rules[7].inp_fuzzy_set[1] = in_ps;
	fl->rules[7].out_fuzzy_set = out_ps;
   fl->rules[8].inp_fuzzy_set[0] = in_ps;
	fl->rules[8].inp_fuzzy_set[1] = in_ps;
   fl->rules[8].out_fuzzy_set = out_pm;
	fl->rules[9].inp_fuzzy_set[0] = in_pl;
   fl->rules[9].inp_fuzzy_set[1] = in_ps;
	fl->rules[9].out_fuzzy_set = out_pm;
	
	fl->rules[10].inp_fuzzy_set[0] = in_nl;
   fl->rules[10].inp_fuzzy_set[1] = in_ze;
	fl->rules[10].out_fuzzy_set = out_nm;
   fl->rules[11].inp_fuzzy_set[0] = in_ns;
	fl->rules[11].inp_fuzzy_set[1] = in_ze;
   fl->rules[11].out_fuzzy_set = out_ns;
	fl->rules[12].inp_fuzzy_set[0] = in_ze;
   fl->rules[12].inp_fuzzy_set[1] = in_ze;
	fl->rules[12].out_fuzzy_set = out_ze;
   fl->rules[13].inp_fuzzy_set[0] = in_ps;
	fl->rules[13].inp_fuzzy_set[1] = in_ze;
   fl->rules[13].out_fuzzy_set = out_ps;
	fl->rules[14].inp_fuzzy_set[0] = in_pl;
   fl->rules[14].inp_fuzzy_set[1] = in_ze;
	fl->rules[14].out_fuzzy_set = out_pm;
	
	fl->rules[15].inp_fuzzy_set[0] = in_nl;
   fl->rules[15].inp_fuzzy_set[1] = in_ns;
	fl->rules[15].out_fuzzy_set = out_nm;
   fl->rules[16].inp_fuzzy_set[0] = in_ns;
	fl->rules[16].inp_fuzzy_set[1] = in_ns;
   fl->rules[16].out_fuzzy_set = out_nm;
	fl->rules[17].inp_fuzzy_set[0] = in_ze;
   fl->rules[17].inp_fuzzy_set[1] = in_ns;
	fl->rules[17].out_fuzzy_set = out_ns;
   fl->rules[18].inp_fuzzy_set[0] = in_ps;
	fl->rules[18].inp_fuzzy_set[1] = in_ns;
   fl->rules[18].out_fuzzy_set = out_ps;
	fl->rules[19].inp_fuzzy_set[0] = in_pl;
   fl->rules[19].inp_fuzzy_set[1] = in_ns;
	fl->rules[19].out_fuzzy_set = out_ps;
	
	fl->rules[20].inp_fuzzy_set[0] = in_nl;
   fl->rules[20].inp_fuzzy_set[1] = in_nl;
	fl->rules[20].out_fuzzy_set = out_ns;
   fl->rules[21].inp_fuzzy_set[0] = in_ns;
	fl->rules[21].inp_fuzzy_set[1] = in_nl;
   fl->rules[21].out_fuzzy_set = out_nm;
	fl->rules[22].inp_fuzzy_set[0] = in_ze;
   fl->rules[22].inp_fuzzy_set[1] = in_nl;
	fl->rules[22].out_fuzzy_set = out_ns;
   fl->rules[23].inp_fuzzy_set[0] = in_ps;
	fl->rules[23].inp_fuzzy_set[1] = in_nl;
   fl->rules[23].out_fuzzy_set = out_ze;
	fl->rules[24].inp_fuzzy_set[0] = in_pl;
   fl->rules[24].inp_fuzzy_set[1] = in_nl;
	fl->rules[24].out_fuzzy_set = out_ps;
	
      return;
}


void initMembershipFunctions(fuzzy_system_rec *fl) {
	
	//  (Y) A = 1, B = 1,  (X) C= 1 D = 2
	float CONST_SCALAR = 1; //CONST_SCALAR * 
	//Y membership function
	
	fl->inp_mem_fns[in_Y][in_nl] = init_trapz (CONST_SCALAR * -0.28,CONST_SCALAR * -0.14,0.0,0.0,left_trapezoid);
   fl->inp_mem_fns[in_Y][in_ns] = init_trapz (CONST_SCALAR * -0.28,CONST_SCALAR * -0.14,CONST_SCALAR * -0.14,0.0,regular_trapezoid);
   fl->inp_mem_fns[in_Y][in_ze] = init_trapz (CONST_SCALAR * -0.14,0.0,0.0,CONST_SCALAR * 0.14,regular_trapezoid);
	fl->inp_mem_fns[in_Y][in_ps] = init_trapz (0.0,CONST_SCALAR * 0.14,CONST_SCALAR * 0.14,CONST_SCALAR * 0.28,regular_trapezoid);
   fl->inp_mem_fns[in_Y][in_pl] = init_trapz (CONST_SCALAR * 0.14,CONST_SCALAR * 0.28,0.0,0.0,right_trapezoid);
	
	//X membership function
	
	
	fl->inp_mem_fns[in_X][in_nl] = init_trapz (CONST_SCALAR * -5.5,CONST_SCALAR * -3.5,0,0,left_trapezoid);
   fl->inp_mem_fns[in_X][in_ns] = init_trapz (CONST_SCALAR * -6.0,CONST_SCALAR * -3.5,CONST_SCALAR * -2.5,0.0,regular_trapezoid);
   fl->inp_mem_fns[in_X][in_ze] = init_trapz (CONST_SCALAR * -3.5,0.0,0.0,CONST_SCALAR * 3.5,regular_trapezoid);
	fl->inp_mem_fns[in_X][in_ps] = init_trapz (0.0,CONST_SCALAR * 2.5,CONST_SCALAR * 3.5,CONST_SCALAR * 6.0,regular_trapezoid);
   fl->inp_mem_fns[in_X][in_pl] = init_trapz (CONST_SCALAR * 3.5,CONST_SCALAR * 5.5,0,0,right_trapezoid);
	
	

   return;
	
	
}

void initFuzzySystem (fuzzy_system_rec *fl) {

   //Note: The settings of these parameters will depend upon your fuzzy system design
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 25; 
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 9;  
	
	
	//Sample only
	// fl->output_values [out_nvl]=-95.0;
	// fl->output_values [out_nl] = -85.0;
	
	//Ran added here:
   float CONST_SCALAR_FORCE = 2.5; // CONST_SCALAR_FORCE * 
	fl->output_values [out_nvl]= CONST_SCALAR_FORCE * -100.0;
	fl->output_values [out_nl]= CONST_SCALAR_FORCE * -100.0;
	fl->output_values [out_nm]= CONST_SCALAR_FORCE * -70.0;
	fl->output_values [out_ns]= CONST_SCALAR_FORCE * -30.0;
	fl->output_values [out_ps]= CONST_SCALAR_FORCE * 30.0;
	fl->output_values [out_pm]= CONST_SCALAR_FORCE * 70.0;
	fl->output_values [out_pl]= CONST_SCALAR_FORCE * 100.0;
	fl->output_values [out_pvl]= CONST_SCALAR_FORCE * 100.0;
	fl->output_values [out_ze]= 0.0;

   

   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
   initFuzzyRules(fl);
   initMembershipFunctions(fl);
   return;
}

//////////////////////////////////////////////////////////////////////////////

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ) {
	
   trapezoid trz;
   trz.a = x1;
   trz.b = x2;
   trz.c = x3;
   trz.d = x4;
   trz.tp = typ;
   switch (trz.tp) {
	   
      case regular_trapezoid:
         	 trz.l_slope = 1.0/(trz.b - trz.a);
         	 trz.r_slope = 1.0/(trz.c - trz.d);
         	 break;
	 
      case left_trapezoid:
         	 trz.r_slope = 1.0/(trz.a - trz.b);
         	 trz.l_slope = 0.0;
         	 break;
	 
      case right_trapezoid:
         	 trz.l_slope = 1.0/(trz.b - trz.a);
         	 trz.r_slope = 0.0;
         	 break;
   }  /* end switch  */
   
   return trz;
}  /* end function */

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
float trapz (float x, trapezoid trz) {
   switch (trz.tp) {
	   
      case left_trapezoid:
         	 if (x <= trz.a)
         	    return 1.0;
         	 if (x >= trz.b)
         	    return 0.0;
         	 /* a < x < b */
         	 return trz.r_slope * (x - trz.b);
	 
	 
      case right_trapezoid:
         	 if (x <= trz.a)
         	    return 0.0;
         	 if (x >= trz.b)
         	    return 1.0;
         	 /* a < x < b */
         	 return trz.l_slope * (x - trz.a);
	 
      case regular_trapezoid:
         	 if ((x <= trz.a) || (x >= trz.d))
         	    return 0.0;
         	 if ((x >= trz.b) && (x <= trz.c))
         	    return 1.0;
         	 if ((x >= trz.a) && (x <= trz.b))
         	    return trz.l_slope * (x - trz.a);
         	 if ((x >= trz.c) && (x <= trz.d))
         	    return  trz.r_slope * (x - trz.d);
         	    
	 }  /* End switch  */
	 
   return 0.0;  /* should not get to this point */
}  /* End function */

//////////////////////////////////////////////////////////////////////////////
float min_of(float values[],int no_of_inps) {
   int i;
   float val;
   val = values [0];
   for (i = 1;i < no_of_inps;i++) {
       if (values[i] < val)
	  val = values [i];
   }
   return val;
}



//////////////////////////////////////////////////////////////////////////////
float fuzzy_system (float inputs[],fuzzy_system_rec fz) {
   int i,j;
   short variable_index,fuzzy_set;
   float sum1 = 0.0,sum2 = 0.0,weight;
   float m_values[MAX_NO_OF_INPUTS];
   
   for (i = 0;i < fz.no_of_rules;i++) {
   	//if (((i+1)%2 == 0)&&(i!=0)) continue;//USED for change from 25 rules to 13 rules
   	//not stable enough to test. give up for now
      for (j = 0;j < fz.no_of_inputs;j++) {
      	
	   variable_index = fz.rules[i].inp_index[j];
	   fuzzy_set = fz.rules[i].inp_fuzzy_set[j];
	   m_values[j] = trapz(inputs[variable_index],
	       fz.inp_mem_fns[variable_index][fuzzy_set]);
	   } /* end j  */
      //original code below
       weight = min_of (m_values,fz.no_of_inputs);
		 //Ran added here
		 //if(i<25) {
			 //weight = min_of (m_values,fz.no_of_inputs);
		 //} else {
			 //weight = min_of (m_values,fz.no_of_inputs);
		 //}


		
       sum1 += weight * fz.output_values[fz.rules[i].out_fuzzy_set];
       sum2 += weight;
       
		
   } /* end i  */
 
	
	if (fabs(sum2) < TOO_SMALL) {
      cout << "\r\nFLPRCS Error: Sum2 in fuzzy_system is 0.  Press key: " << endl;
      //~ getch();
      //~ exit(1);
      return 0.0;
  }
   	cout<< "sum2 = " << sum2<<endl;
   
   
   return (sum1/sum2);
}  /* end fuzzy_system  */

//////////////////////////////////////////////////////////////////////////////
void free_fuzzy_rules (fuzzy_system_rec *fz) {
   if (fz->allocated){
	   free (fz->rules);
	}
	
   fz->allocated = false;
   return;
}

