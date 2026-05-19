/*
언리얼에서는 printf스타일의 출력을 사용하기 때문에 printf를 사용하자

\n, \r
윈도우에서는 전자만 해도 둘 다 되는 효과
이외의 운영체제는 둘 다 해줘야 정상 동작
*/

/*

	cout << "■□■□■□■□■□■□■□■□\n";
	cout << "↑→↓↓↓\n";
	cout << "↓←↓→↑←↓\n";

	cout << "\n";

	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = i; j < 10; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	for (int i = 10; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = i; j < 10; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	int height;
	cin >> height;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < height - i - 1; j++)
			cout << " ";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << "*";

		cout << "\n";
	}
	return 0;
*/
// 