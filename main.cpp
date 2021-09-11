#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t readnum(char *filename)
{
    //파일 읽기
    FILE *fp = fopen(filename, "rb");
    char buf[5] = {};
    fread(buf, sizeof(char), 4, fp);
    fclose(fp);

    //숫자 변환
    uint32_t *p = reinterpret_cast<uint32_t *>(buf);
    return ntohl(*p);
}

int main(int argc, char **argv)
{
    //매개변수는 2개
    if (argc != 3)
    {
        printf("argc must be 3!!\n");
        exit(1);
    }

    //숫자 읽기
    uint32_t first = readnum(argv[1]);
    uint32_t second = readnum(argv[2]);
    uint32_t sum = first + second;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", first, first, second, second, sum, sum);
    return 0;
}