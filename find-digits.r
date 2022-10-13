nums <- scan("stdin",sep=" ")
n<-nums[1] #number of testcases
nums2<-nums[-1] # with out the number of test cases

for(i in 1:n)
    {
        ea=0
        length<-floor (log10 (abs (nums2[i]))) + 1
        char<-as.character(nums2[i])
        x<-is.character(char)
        char2<-as.numeric(unlist(strsplit(char,"")))
        for(j in 1:length)
            {
                if(char2[j] != 0)
               {
                char3<-nums2[i]%%char2[j]
                 }
                else if(char2[j] == 0)
                    {
                    char3<-1
                }

            if(char3==0)
                {
                    ea=ea+1
                }

                

            
            }
         write.table(ea, sep = "", append=T, row.names = F, col.names = F,quote=F)
        

       

  
    }
