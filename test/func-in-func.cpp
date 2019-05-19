int fun()
{
    int i = 3;
    auto ff = [&]() {
        return i * i;
    };
    return ff();
}

int main()
{
    int a = fun();
}