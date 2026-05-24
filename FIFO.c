#include<stdio.h>
#include<unistd.h>
int main(){
    int frames[10], pages[50], n, f;
    int front = 0;
    int pageHits = 0, pageFaults = 0;

    printf("Enter no. of pages: ");
    scanf("%d", &n);
    printf("Enter no. of prames: ");
    scanf("%d", &f);
    printf("Enter the page sequence: \n");
    for(int i = 0; i<n; i++){
        scanf("%d", &pages[i]);
    }

    // 1) initaillise frames with -1 -> (empty)
    for(int i = 0; i<f; i++){
        frames[i] = -1;
    }

   printf("FIFO - Page replacements method");

   for(int i = 0; i<n; i++){        // running on pages
        int found = 0;

        // check for hit 
        for(int j=0; j<f; j++){
            if(pages[i] == frames[j]){  // hit 
                found = 1;
                pageHits++;
                break;
            }
        }

        if(found == 0){     // page fault 
            pageFaults++;
            // now check empty slot in frames or not 
            int pos = -1;
            for(int j = 0; j<f; j++){
                if(frames[j] == -1){
                    pos = j;
                    break;
                }
            }

            if(pos != -1){
                frames[pos] = pages[i];
            }else{
                frames[front] = pages[i];
                front = (front + 1) % f;        // always front is (front + 1) % frames number
            }
        }

        printf("Frames: ");

        for(int j = 0; j < f; j++){
            if(frames[j] != -1) printf("%d ", frames[j]);
            else    printf("- ");
        }
        printf("\n");
   }
}