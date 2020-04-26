#include <stdio.h>
#include <stdlib.h>

char* html_head = "<!DOCTYPE html><head>"
			   "<meta charset='utf-8'>"
			   "<meta name='author' content='Sebastião Vicente'>"
			   "<meta name='description' content='blah'>"
			   "<link rel='stylesheet' href='css/main.css'>"
			   "<title> Title </title>"
			   "</head>";

char* html_footer = "<footer> this is the footer </footer>";

typedef struct Content {
	char* data;
} Content;

typedef struct Page {
	char* name;

	Content* contents;
} Page;

void build_content(FILE* f, Content* c){
	if(c == NULL) 
		return;
	
	fputs(c->data, f);
}

void build_page(Content* content){

	/* Create the file */
	FILE* f = fopen("../_site/test.html", "w");

	fputs(html_head, f);
	build_content(f, content->data);
	fputs(html_footer, f);

	fclose(f);
	
}

void build_directory(){
	
	if(mkdir("../_site", 0700) == -1) 
		printf("Unable to create _site directory");	
	if(mkdir("../_site/css", 0700) == -1) 
		printf("Unable to create css directory");
	if(mkdir("../_site/img", 0700) == -1) 
		printf("Unable to create img directory.");
	
	

}

int main(){
	printf("Building directory structure.....");

	build_directory();

	printf(" DONE\n");

	printf("Building content.....");

	Content* content;
	content->data = "teste conteudo";
	build_page(&content);
	
	printf(" DONE\n");


}

