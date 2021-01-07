Action()
{
	int i;
	int j;
	int num;
	int countIBM;
	int valueIBM;
	char* s;
	char* IBM;
	char* valueCompany;
	
		web_url("computers", 
		"URL=http://computer-database.gatling.io/computers", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

		web_reg_find("Text=TSK6",
		"SaveCount=Count",	             
		LAST);
	
		web_submit_data("computers_2", 
		"Action=http://computer-database.gatling.io/computers", 
		"Method=GET", 
		"EncType=", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=f", "Value={RequiredName}", ENDITEM, 
		LAST);
	
		s = lr_eval_string("{Count}");
		i = atoi(s);
		lr_output_message("Chislo name TSK6 in Get_Answer: %s",lr_eval_string("{Count}"));
		
		if (i == 1) {
			
			i = atoi(s) - 1;
			lr_save_int(i, "RealCountTSK6");
			lr_output_message("Chislo name TSK6 on Page: %s",lr_eval_string("{RealCountTSK6}"));
		
		}		
				
		if (i > 1 && i <= 15) {
			
			i = atoi(s) - 5;
			lr_save_int(i, "RealCountTSK6");
			lr_output_message("Chislo name TSK6 on Page: %s",lr_eval_string("{RealCountTSK6}"));
			
		}
		
		if (i > 15) {
			
			i = atoi(s) - 6;
			lr_save_int(i, "RealCountTSK6");
			lr_output_message("Chislo name TSK6 on Page: %s",lr_eval_string("{RealCountTSK6}"));
		}
		
		switch (i) {
				
			case 0:

				lr_output_message("In Get Answer no computer with name -TSK6-, create two computer");
			
				for(j = 0; j<2; j++){
				
				web_url("Add a new computer", 
				"URL=http://computer-database.gatling.io/computers/new", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://computer-database.gatling.io/computers?f={RequiredName}", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				LAST);
		
				web_submit_data("computers_3", 
				"Action=http://computer-database.gatling.io/computers", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://computer-database.gatling.io/computers/new", 
				"Snapshot=t5.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=name", "Value={RequiredName}", ENDITEM, 
				"Name=introduced", "Value=", ENDITEM, 
				"Name=discontinued", "Value=", ENDITEM, 
				"Name=company", "Value={RandomCompany}", ENDITEM, 
				LAST);
				}
				
			break;
			
			case 1:
			
				lr_output_message("In Get Answer one with name -TSK6-, create another one computer");
			
				for(j = 1; j<2; j++){
				
				web_url("Add a new computer", 
				"URL=http://computer-database.gatling.io/computers/new", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://computer-database.gatling.io/computers?f={RequiredName}", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				LAST);
		
				web_submit_data("computers_3", 
				"Action=http://computer-database.gatling.io/computers", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://computer-database.gatling.io/computers/new", 
				"Snapshot=t5.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=name", "Value={RequiredName}", ENDITEM, 
				"Name=introduced", "Value=", ENDITEM, 
				"Name=discontinued", "Value=", ENDITEM, 
				"Name=company", "Value={RandomCompany}", ENDITEM, 
				LAST);
				}
				
			break;
			
			default:
						
				while ( i > 2) {
					
				lr_output_message("In Get Answer more than two computer with name -TSK6-, deleting extra computers in any order");	
				
				lr_save_int(i, "NumberTSK6");
				lr_output_message("Number TSK6 on current page before DELETE: %s",lr_eval_string("{NumberTSK6}"));
				
				web_reg_find("Text=TSK6",
				"SaveCount=Count",	             
				LAST);
				
				num = 1 + rand() % ((i + 1) - 1);;
				lr_save_int(num, "random");
				lr_output_message("random Ordinal for DELETE : %s",lr_eval_string("{random}"));
			
				web_reg_save_param_ex(
				"ParamName=CompId",
				"LB=<td><a href=\"/computers/",
				"RB=\">",
				"Ordinal={random}",
				SEARCH_FILTERS,
				LAST);
				
				web_url("computers_2", 
				"URL=http://computer-database.gatling.io/computers?f={RequiredName}", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://computer-database.gatling.io/computers", 
				"Snapshot=t17.inf", 
				"Mode=HTML", 
				LAST);	
				
				s = lr_eval_string("{Count}");
				i = atoi(s);
				lr_save_int(i, "CountIteration");
				lr_output_message("Count in Get_Answer on current Iteration: %s",lr_eval_string("{CountIteration}"));
							
				web_url("TSK6", 
				"URL=http://computer-database.gatling.io/computers/{CompId}", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://computer-database.gatling.io/computers?f={RequiredName}", 
				"Snapshot=t8.inf", 
				"Mode=HTML", 
				LAST);

				web_submit_data("delete", 
				"Action=http://computer-database.gatling.io/computers/{CompId}/delete", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://computer-database.gatling.io/computers/{CompId}", 
				"Snapshot=t9.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				LAST);
				
				if (i > 1 && i <= 15) {
			
					i = atoi(s) - 5;
					lr_save_int(i, "RealCountTSK6");
					lr_output_message("Chislo name TSK6 on Page on current Iteration: %s",lr_eval_string("{RealCountTSK6}"));
				
				}
		
				if (i > 15) {
			
					i = atoi(s) - 6;
					lr_save_int(i, "RealCountTSK6");
					lr_output_message("Chislo name TSK6 on current Iteration: %s",lr_eval_string("{RealCountTSK6}"));
				
				}
				
				i = i - 1;
		
				}
			
			break;
			
		}
		
		web_reg_find("Text=IBM",
		"SaveCount=CountIBM",	             
		LAST);
	
		web_submit_data("computers_2", 
		"Action=http://computer-database.gatling.io/computers", 
		"Method=GET", 
		"EncType=", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=f", "Value={RequiredName}", ENDITEM, 
		LAST);
	
		IBM = lr_eval_string("{CountIBM}");
		countIBM = atoi(IBM);
		lr_output_message("Chislo name IBM on Page from Get Answer: %s",lr_eval_string("{CountIBM}"));	
		
		if ( countIBM == 1) {
			
			lr_output_message("In Get Answer one computer with Name_Company -IBM-");
			
			for (j = 1; j < 3; j++){
				
				lr_save_int(j, "IterationCycle");
				lr_output_message("Iteration of Cycle: %s",lr_eval_string("{IterationCycle}"));
				
				web_reg_save_param_ex(
				"ParamName=CompIdIBM",
				"LB=<td><a href=\"/computers/",
				"RB=\">",
				"Ordinal={IterationCycle}",
				SEARCH_FILTERS,
				LAST);
				
				web_submit_data("computers_2", 
				"Action=http://computer-database.gatling.io/computers", 
				"Method=GET", 
				"EncType=", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://computer-database.gatling.io/computers", 
				"Snapshot=t2.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=f", "Value={RequiredName}", ENDITEM, 
				LAST);
				
				web_reg_save_param_regexp(
				"ParamName=RequiredValueIBM",
				"RegExp=value=\"(.*)\" selected>",
				"Ordinal=1",
				SEARCH_FILTERS,
				LAST);
				
				web_url("TSK6", 
				"URL=http://computer-database.gatling.io/computers/{CompIdIBM}", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://computer-database.gatling.io/computers?f={CompIdIBM}", 
				"Snapshot=t16.inf", 
				"Mode=HTML", 
				LAST);
				
				lr_output_message("Value of Company in GET Answer (required value company IBM is --13--): %s",lr_eval_string("{RequiredValueIBM}"));
				valueCompany = lr_eval_string("{RequiredValueIBM}");
				valueIBM = atoi(valueCompany);
			
				if( valueIBM == 13 ) {
					
					web_submit_data("610", 
					"Action=http://computer-database.gatling.io/computers/{CompIdIBM}", 
					"Method=POST", 
					"TargetFrame=", 
					"RecContentType=text/html", 
					"Referer=http://computer-database.gatling.io/computers/{CompIdIBM}", 
					"Snapshot=t4.inf", 
					"Mode=HTML", 
					ITEMDATA, 
					"Name=name", "Value={RequiredName}", ENDITEM, 
					"Name=introduced", "Value=", ENDITEM, 
					"Name=discontinued", "Value=", ENDITEM, 
					"Name=company", "Value=1", ENDITEM, 
					LAST);
					
					lr_output_message("Entering ID of computer is: %s",lr_eval_string("{CompIdIBM}"));
					
					break;
					
				}
			
			
			}
			
		}		
		
		if ( countIBM == 0 || countIBM == 2) {
				
			
			if ( countIBM == 2) {
				
				lr_output_message("In Get Answer two computer with Name_Company -IBM-");
			
			}
			
			web_reg_save_param_ex(
			"ParamName=CompIdIBM",
			"LB=<td><a href=\"/computers/",
			"RB=\">",
			"Ordinal={randomIBM}",
			SEARCH_FILTERS,
			LAST);
				
			web_submit_data("computers_2", 
			"Action=http://computer-database.gatling.io/computers", 
			"Method=GET", 
			"EncType=", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://computer-database.gatling.io/computers", 
			"Snapshot=t2.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=f", "Value={RequiredName}", ENDITEM, 
			LAST);
				
			web_url("TSK6", 
			"URL=http://computer-database.gatling.io/computers/{CompIdIBM}", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://computer-database.gatling.io/computers?f={RequiredName}", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);

			if (countIBM == 0) {
				
				lr_output_message("In Get Answer no one computer with Company -IBM-");
				      	
				web_submit_data("610", 
				"Action=http://computer-database.gatling.io/computers/{CompIdIBM}", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://computer-database.gatling.io/computers/{CompIdIBM}", 
				"Snapshot=t4.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=name", "Value={RequiredName}", ENDITEM, 
				"Name=introduced", "Value=", ENDITEM, 
				"Name=discontinued", "Value=", ENDITEM, 
				"Name=company", "Value={CompanyIBM}", ENDITEM, 
				LAST);
				
				}
				      
			lr_output_message("Random entering Ordinal is: %s",lr_eval_string("{randomIBM}"));
			lr_output_message("Entering ID of computer is: %s",lr_eval_string("{CompIdIBM}"));
				
		}		
	
	return 0;
}
