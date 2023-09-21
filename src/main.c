int main(void) {
    printf("Hello world\n");

    __builtin_trap();
    printf("Hello world\n");
    return 0;
}
