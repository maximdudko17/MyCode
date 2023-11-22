#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define MEM_STEP 5

struct Text{
    struct Sentence **text;
    int size;
    int n;
};

struct Sentence{
    char *str;
    int size;
};

struct Data {
    int year;
    int month;
    int day;
};
int cmp(const void* a, const void* b) {
    struct Data aa = *((struct Data *) a);
    struct Data bb = *((struct Data *) b);
    if ((aa.year) > (bb.year)) return 1;
    if ((aa.year) < (bb.year)) return -1;
    if ((aa.year) == (bb.year)) {
        if ((aa.month) > (bb.month)) return 1;
        if ((aa.month) < (bb.month)) return -1;
        if ((aa.month) == (bb.month)) {
            if ((aa.day) > (bb.day)) return 1;
            if ((aa.day) < (bb.day)) return -1;
        }
    }
    return 0;
}


void func_data(struct Text text){ // func 1
    struct Data *data = malloc(sizeof(struct Data)*100);
    int count = 0;
    int p = 0;
    for(int i = 0; i < text.n; i++){
        char strcopy[strlen(text.text[i]->str)];
        strcpy(strcopy, text.text[i]->str);
        char temp;
        for(int j = 0; j < strlen(text.text[i]->str); j++){
            temp = text.text[i]->str[j];
            if (temp == 'd' && isdigit(text.text[i]->str[j+1]) && isdigit(text.text[i]->str[j+2]) &&
            (text.text[i]->str[j+3]) == 'm' && isdigit(text.text[i]->str[j+4]) && isdigit(text.text[i]->str[j+5]) &&
            text.text[i]->str[j+6] == 'y' && isdigit(text.text[i]->str[j+7]) && isdigit(text.text[i]->str[j+8]) &&
            isdigit(text.text[i]->str[j+9]) && isdigit(text.text[i]->str[j+10]) ){
                char* d = strtok(strcopy + j + 1, "m");
                int int_d = atoi(d);

                char* m = strtok(strcopy + j + 4, "y");
                int int_m = atoi(m);

                char* y = strtok(strcopy + j + 7, " .,");
                int int_y = atoi(y);

                data[p].year = int_y;
                data[p].month = int_m;
                data[p].day = int_d;
                count++;
                p++;
            }
            }
        }
    qsort(data, count,sizeof(struct Data),cmp);

    for(int g = 0; g < count; g++){
        printf("%02d%c%02d%c%04d\n", data[g].day,':',data[g].month,':',data[g].year);
    }
    free(data);
    }





void delete_odd_count(struct Text text) { // 2 func
    int k = 0;
    while (k < text.n) {
        int i = 0;
        int s = 0;
        char temp;
        while (i < strlen(text.text[k]->str)) {
            temp = text.text[k]->str[i];
            i++;
            if (temp == '\n' || temp == '.' || temp == '!' || temp == ' ') continue;
            i--;
            int j = i;
            do {
                j++;
                temp = text.text[k]->str[j];
            } while (temp != '\n' && temp != '.' && temp != '!' && temp != ' ' && temp != ',');
            s++;
            i = j;
        }

        if (s % 2 == 1) {
            memmove(text.text + k, text.text + k + 1,(text.n - k - 1) * sizeof(*text.text));
            text.n--;
        } else k++;
    }
}

void func_tolower(struct Text text) { //3 func
    int k = 0;
    while (k < text.n) {
        int i = 0;
        char temp;
        while (i < strlen(text.text[k]->str)) {
            temp = text.text[k]->str[i];
            i++;
            if (temp == '\n' || temp == '.' || temp == '!' || temp == ' ') continue;
            i--;
            int j = i;
            int count = 0;
            int count_digit = 0;
            do {
                j++;
                temp = text.text[k]->str[j];
                if (isdigit(temp)) {
                    count_digit++;
                }
                count++;
            } while (temp != '\n' && temp != '.' && temp != '!' && temp != ' ' && temp != ',');
            if (count_digit == 0){
                for (int p = 0; p < count - 1; p++) {
                    text.text[k]->str[i] = tolower(text.text[k]->str[i]);
                    i++;
                }
            }
            i = j;
        }
        k++;
    }
}


void func_uper(struct Text text){   //func 4
    int c;
    for(int i = 0; i < text.n; i++){
        char temp;
        c = 0;
        for(int j = 0; j < strlen(text.text[i]->str); j++){
            temp = text.text[i]->str[j];
            if(isupper(temp)){
                c++;
            }

        }
        if(c == 0){
            printf("%s\n", text.text[i]->str);
        }
    }
}


    struct Sentence *read_sentence() {
        int size = MEM_STEP;
        char *buf = malloc(size * sizeof(char));
        char temp = getchar();
        int n = 0;
        do {
            if (n >= size - 2) {
                char *t = realloc(buf, size + MEM_STEP);
                if (!t) {
                    return NULL;
                }
                size += MEM_STEP;
                buf = t;
            }

            buf[n] = temp;
            temp = getchar();
            n++;

        } while (temp != '\n' && temp != '.');

        buf[n] = temp;
        buf[n + 1] = '\0';
        if (buf[0] == '\n') {
            buf++;
        }


        struct Sentence *sentence = malloc(sizeof(struct Sentence));
        sentence->str = buf;
        sentence->size = n;
        return sentence;
    }

    int unique_sent(struct Sentence **txt, struct Sentence *sent, int n) {
        for (int i = 0; i < n; i++) {
            int k = 0;
            for (int j = 0; j < strlen(sent->str); j++) {
                if (toupper(txt[i]->str[j]) == toupper(sent->str[j]))
                    k++;

            }
            if (k == strlen(sent->str) && k == strlen(txt[i]->str))
                return 0;

        }
        return 1;
    }


    struct Text read_text() {
        int size = MEM_STEP;
        struct Sentence **text = malloc(size * sizeof(struct Sentence *));
        struct Sentence *temp;
        int n = 0;
        int nlcount = 0;

        do {
            temp = read_sentence();

            if (n >= size - 2) {
                struct Sentence **t = realloc(text, (size + MEM_STEP) * sizeof(struct Sentence *));

                if (!t) {
                    puts("Allocation error");
                }

                text = t;
                size += MEM_STEP;
            }
            if (temp->str[0] == '\n' && temp->str[1] == '\0') {
                nlcount++;

            } else {
                while (temp->str[0] == '\t' || temp->str[0] == ' ' || temp->str[0] == '\n') {
                    temp->str++;
                }
                nlcount = 0;
                if (unique_sent(text, temp, n)) {
                    text[n] = temp;
                    n++;
                }
            }
        } while (nlcount < 1);

        struct Text txt;
        txt.text = text;
        txt.size = size;
        txt.n = n;
        return txt;
    }


    int main() {
        setlocale(LC_ALL, "");

        puts("Введите текст, по окончании ввода нажмите два раза Enter:");

        struct Text res = read_text();

        puts("Введите номер одного из доступных действий:");
        puts("1)Найти во всем тексте даты записанные в подстроке вида “d<day>m<month>y<year>” и вывести все даты по возрастанию в формате “DD:MM:YYYY:. Пример даты в тексте, “d14m03y0988”. ");
        puts("2)Удалить все предложения в которых количество слов нечетно.");
        puts("3)Преобразовать все слова в которых нет цифр так, чтобы все буквы кроме последней были прописными.");
        puts("4)Вывести все предложения в которых нет заглавных букв..\n");
        int a;
        scanf("%d", &a);
        puts("\nРезультат:\n");

        switch (a) {
            case 1:
                func_data(res);
                break;

            case 2:
                delete_odd_count(res);
                for (int i = 0; i < res.n; i++) {
                    printf("%s\n", res.text[i]->str);
                }
                puts("\n");
                break;
            case 3:
                func_tolower(res);
                for (int i = 0; i < res.n; i++) {
                    printf("%s\n", res.text[i]->str);
                }
                puts("\n");
                break;
            case 4:
                func_uper(res);
                break;
            default:
                puts("Данные некорректы");

        }
        printf("\n");
        for (int i = 0; i < res.n; i++) {
            free(res.text[i]);
        }
        free(res.text);
    }

