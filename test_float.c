#include "includes/printf.h"
#include <stdio.h>

int     main()
{
	printf("---- Float ----\n\n");

	ft_printf("[%d]\n", ft_printf("|%01.f| |%02.f| |%03.f| |%1.f| |%2.f| |%.1f| |%.20f|\n", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("[%d]\n", printf("|%01.f| |%02.f| |%03.f| |%1.f| |%2.f| |%.1f| |%.20f|\n", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("\n");
	
	ft_printf("[%d]\n", ft_printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f| |%5.f| |%-5.f|\n", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("[%d]\n", printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f| |%5.f| |%-5.f|\n",  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	
	printf("\n");
	ft_printf("[%d]\n", ft_printf("|%01.f| |%02.f| |%-03.f| |%1.f| |%2.f| |%-.1f| |%-.2f|\n",  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("[%d]\n", printf("|%01.f| |%02.f| |%-03.f| |%1.f| |%2.f| |%-.1f| |%-.2f|\n",  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

	ft_printf("[%d]\n", ft_printf("|%01.f| |%02.f| |%03.f| |%1.f| |%2.f| |%.1f| |%.20f|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	printf("[%d]\n", printf("|%01.f| |%02.f| |%03.f| |%1.f| |%2.f| |%.1f| |%.20f|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f| |%5.f| |%-5.f|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	printf("[%d]\n", printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f| |%5.f| |%-5.f|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	
	printf("\n");
	ft_printf("[%d]\n", ft_printf("|%01.f| |%02.f| |%-03.f| |%1.f| |%2.f| |%-.1f| |%-.2f|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	printf("[%d]\n", printf("|%01.f| |%02.f| |%-03.f| |%1.f| |%2.f| |%-.1f| |%-.2f|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));

	printf("\n");
	ft_printf("[%d]\n", ft_printf("|%.1f| |%.2f| |%.3f| |%.4f| |%.5f| |%.6f| |%.1f| |%20.10f|\n", 22.16, 32.2191, 42.355556, 52.4555555, 62.5555555, 72.6999999, 82.76, 0.000000));
	printf("[%d]\n", printf("|%.1f| |%.2f| |%.3f| |%.4f| |%.5f| |%.6f| |%.1f| |%20.10f|\n", 22.16, 32.2191, 42.355556, 52.4555555, 62.5555555, 72.6999999, 82.76, 0.000000));

	ft_printf("[%d]\n", ft_printf("|%01.lf| |%02.lf| |%03.lf| |%1.lf| |%2.lf| |%.1lf| |%.20lf|\n", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("[%d]\n", printf("|%01.lf| |%02.lf| |%03.lf| |%1.lf| |%2.lf| |%.1lf| |%.20lf|\n", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("\n");
	
	ft_printf("[%d]\n", ft_printf("|%10.Lf| |%-10.Lf| |%10.Lf| |%10.Lf| |%-10.Lf| |%5.Lf| |%-5.Lf|\n", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("[%d]\n", printf("|%10.Lf| |%-10.Lf| |%10.Lf| |%10.Lf| |%-10.Lf| |%5.Lf| |%-5.Lf|\n",  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	
	printf("\n");
	ft_printf("[%d]\n", ft_printf("|%01.lf| |%02.lf| |%-03.lf| |%1.Lf| |%2.Lf| |%-.1Lf| |%-.2Lf|\n",  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("[%d]\n", printf("|%01.lf| |%02.lf| |%-03.lf| |%1.Lf| |%2.Lf| |%-.1Lf| |%-.2Lf|\n",  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

	ft_printf("[%d]\n", ft_printf("|%01.Lf| |%02.Lf| |%03.Lf| |%1.Lf| |%2.Lf| |%.1Lf| |%.20Lf|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	printf("[%d]\n", printf("|%01.Lf| |%02.Lf| |%03.Lf| |%1.Lf| |%2.Lf| |%.1Lf| |%.20Lf|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	printf("\n");

	ft_printf("[%d]\n", ft_printf("|%10.Lf| |%-10.Lf| |%10.Lf| |%10.Lf| |%-10.Lf| |%5.Lf| |%-5.Lf|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	printf("[%d]\n", printf("|%10.Lf| |%-10.Lf| |%10.Lf| |%10.Lf| |%-10.Lf| |%5.Lf| |%-5.Lf|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	
	printf("\n");
	ft_printf("[%d]\n", ft_printf("|%01.Lf| |%02.Lf| |%-03.Lf| |%1.Lf| |%2.Lf| |%-.1Lf| |%-.2Lf|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	printf("[%d]\n", printf("|%01.Lf| |%02.Lf| |%-03.Lf| |%1.Lf| |%2.Lf| |%-.1Lf| |%-.2Lf|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));

	printf("\n");
	ft_printf("[%d]\n", ft_printf("|%.1Lf| |%.2Lf| |%.3Lf| |%.4Lf| |%.5Lf| |%.6Lf| |%.1Lf| |%20.10Lf|\n", 22.16, 32.2191, 42.355556, 52.4555555, 62.5555555, 72.6999999, 82.76, 0.000000));
	printf("[%d]\n", printf("|%.1Lf| |%.2Lf| |%.3Lf| |%.4Lf| |%.5Lf| |%.6Lf| |%.1Lf| |%20.10Lf|\n", 22.16, 32.2191, 42.355556, 52.4555555, 62.5555555, 72.6999999, 82.76, 0.000000));

	ft_printf("[%d]\n", ft_printf("|%10.lf| |%-10.lf| |%10.lf| |%10.lf| |%-10.lf| |%5.lf| |%-5.lf|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	printf("[%d]\n", printf("|%10.lf| |%-10.lf| |%10.lf| |%10.lf| |%-10.lf| |%5.lf| |%-5.lf|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	
	printf("\n");
	ft_printf("[%d]\n", ft_printf("|%01.lf| |%02.lf| |%-03.lf| |%1.lf| |%2.lf| |%-.1lf| |%-.2lf|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));
	printf("[%d]\n", printf("|%01.lf| |%02.lf| |%-03.lf| |%1.lf| |%2.lf| |%-.1lf| |%-.2lf|\n", 22.1, 32.2, 42.3, 52.4, 62.5, 72.6, 82.7));

	printf("\n");
	ft_printf("[%d]\n", ft_printf("|%.1lf| |%.2lf| |%.3lf| |%.4lf| |%.5lf| |%.6lf| |%.1lf| |%20.10lf|\n", 22.16, 32.2191, 42.355556, 52.4555555, 62.5555555, 72.6999999, 82.76, 0.000000));
	printf("[%d]\n", printf("|%.1lf| |%.2lf| |%.3lf| |%.4lf| |%.5lf| |%.6lf| |%.1lf| |%20.10lf|\n", 22.16, 32.2191, 42.355556, 52.4555555, 62.5555555, 72.6999999, 82.76, 0.000000));

	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01.10f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 50.001448585799999999, 50.2548, 50.2548, 50.2548, 50.2548));
	printf("%d\n", printf("|%#01.10f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 50.001448585799999999, 50.2548, 50.2548, 50.2548, 50.2548));

ft_printf("%d\n", ft_printf("|%#01.10f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 50.001448585799999999, 50.2548, 50.2548, 50.2548, 50.2548));
printf("%d\n", printf("|%#01.10f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 50.001448585799999999, 50.2548, 50.2548, 50.2548, 50.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%01.f| |%02.f| |%03.f| |%1.f| |%2.f|\n", -450.2548, 200.2548, 960000.2548, 20.2548, -10.2548));
printf("%d\n", printf("|%01.f| |%02.f| |%03.f| |%1.f| |%2.f|\n", -450.2548, 200.2548, 960000.2548, 20.2548, -10.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01.f| |%#02.f| |%03.f| |%1.f| |%2.f|\n", -450.2548, 200.2548, 960000.2548, 20.2548, -10.2548));
printf("%d\n", printf("|%#01.f| |%#02.f| |%03.f| |%1.f| |%2.f|\n", -450.2548, 200.2548, 960000.2548, 20.2548, -10.2548));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%-.1f| |%-.2f|\n", 50.2548, 50.2548));
printf("[%d]\n", printf("|%-.1f| |%-.2f|\n", 50.2548, 50.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%5.f| |%-.2f| |%-.1f| |%-.2f|\n", 00.00, 00.00, 00.00, 00.00));
printf("[%d]\n", printf("|%5.f| |%-.2f| |%-.1f| |%-.2f|\n", 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%#0-10f| |%#0+10f| |%#0+10.f| |%#0-10.f|\n", 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%#0-10f| |%#0+10f| |%#0+10.f| |%#0-10.f|\n", 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%-.2f| |%5.f| |%-5.f|\n", 50.2548, 00.00, 00.00));
printf("%d\n", printf("|%-.2f| |%5.f| |%-5.f|\n", 50.2548, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 150.2548, 3000.2548, 1400.2548, 90.2548, 70.2548));
printf("%d\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 150.2548, 3000.2548, 1400.2548, 90.2548, 70.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%-1.5f| |%+2.4f| |%-3.f| |%-1.f| |%-2.f|\n", 12.68999, 78.68999, 58.68999, 8.68999, 48.68999));
printf("%d\n", printf("|%-1.5f| |%+2.4f| |%-3.f| |%-1.f| |%-2.f|\n",  12.68999, 78.68999, 58.68999, 8.68999, 48.68999));
printf("\n");

ft_printf("%d\n", ft_printf("|%-3.1f| |%5.2f| |%+1.0f| |%+0.2f|\n", 1.68999, 0.68999, 15488.68999, 203.68999));
printf("%d\n", printf("|%-3.1f| |%5.2f| |%+1.0f| |%+0.2f|\n", 1.68999, 0.68999, 15488.68999, 203.68999));
printf("\n");

ft_printf("%d\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.68999, 3.68999, 1.68999, 9.68999, 7.68999));
printf("%d\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.68999, 3.68999, 1.68999, 9.68999, 7.68999));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 4.68999, 2.68999, 4.68999, 1.68999, 5.68999));
printf("%d\n", printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f| \n", 4.68999, 2.68999, 4.68999, 1.68999, 5.68999));
printf("\n");

ft_printf("%d\n", ft_printf("|%#0+10.f| |%#0-10.f| |%+1.0f| |%+0.2f|\n", 9.68999, 8.68999, 15.68999, 9.68999));
printf("%d\n", printf("|%#0+10.f| |%#0-10.f| |%+1.0f| |%+0.2f|\n", 9.68999, 8.68999, 15.68999, 9.68999));
printf("\n");

ft_printf("%d\n", ft_printf("|% .10lf| |%-.10f| |%+.10f| |% .10f| |%- .5f|\n", 49.00025, 2.00025, 4.00025, 1.00025, 5.00025));
printf("%d\n", printf("|% .10lf| |%-.10f| |%+.10f| |% .10f| |%- .5f|\n", 49.00025, 2.00025, 4.00025, 1.00025, 5.00025));
printf("\n");

ft_printf("%d\n", ft_printf("|%10.lf| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 4.00025, 2.00025, 4.00025, 1.00025, 5.00025));
printf("%d\n", printf("|%10.lf| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 4.00025, 2.00025, 4.00025, 1.00025, 5.00025));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%5.f| |%-5.f| |%+ .5f| |%+ .10f|\n", 9.00025, 8.00025, 15.00025, 15.00025));
printf("[%d]\n", printf("|%5.f| |%-5.f| |%+ .5f| |%+ .10f|\n", 9.00025, 8.00025, 15.00025, 15.00025));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 5.00025, 5.00025, 5.00025, 5.00025, 5.00025));
printf("[%d]\n", printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 5.00025, 5.00025, 5.00025, 5.00025, 5.00025));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#01.f| |%#02.f| |%03.f| |%1.f| |%2.f|\n", -45.00025, 20.00025, 96000.00025, 2.00025, -1.00025));
printf("[%d]\n", printf("|%#01.f| |%#02.f| |%03.f| |%1.f| |%2.f|\n", -45.00025, 20.00025, 96000.00025, 2.00025, -1.00025));


ft_printf("[%d]\n", ft_printf("|%.1f| |%.2f| |%-.1f| |%-.2f|\n",00.6054, 00.47406, 5.00025, 5.00025));
printf("[%d]\n", printf("|%.1f| |%.2f| |%-.1f| |%-.2f|\n", 00.6054, 00.47406, 5.00025, 5.00025));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 25.00, 25.00, 25.00, 25.00, 25.00));
printf("[%d]\n", printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 25.00, 25.00, 25.00, 25.00, 25.00));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 25.00, 25.00, 25.00, 25.00, 25.00));
printf("[%d]\n", printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 25.00, 25.00, 25.00, 25.00, 25.00));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%5.f| |%-.2f| |%-.1f| |%-.2f|\n", 0.5, 0.5, 0.5, 0.5));
printf("[%d]\n", printf("|%5.f| |%-.2f| |%-.1f| |%-.2f|\n", 0.5, 0.5, 0.5, 0.5));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 0.4859, 0.4859, 0.4859, 0.4859, 0.4859));
printf("[%d]\n", printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 0.4859, 0.4859, 0.4859, 0.4859, 0.4859));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 0.4859, 0.4859, 0.4859, 0.4859, 0.4859));
printf("[%d]\n", printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 0.4859, 0.4859, 0.4859, 0.4859, 0.4859));

ft_printf("[%d]\n", ft_printf("|%#0+10.f| |%#0-10.f| |%5.f| |%-5.f|\n", 0004.52, 0004.52, 0004.52, 0004.52));
printf("[%d]\n", printf("|%#0+10.f| |%#0-10.f| |%5.f| |%-5.f|\n", 0004.52, 0004.52, 0004.52, 0004.52));

ft_printf("[%d]\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 1004.525, 3004.5200, 1004.5240, 9004.52, 7004.52));
printf("[%d]\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 1004.525, 3004.5200, 1004.5240, 9004.52, 7004.52));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%-1.5f| |%+2.4f| |%-3.f| |%-1.f| |%-2.f|\n", 1004.5225, 7004.528, 5004.528, 8004.52, 4004.528));
printf("[%d]\n", printf("|%-1.5f| |%+2.4f| |%-3.f| |%-1.f| |%-2.f|\n",  1004.5225, 7004.528, 5004.528, 8004.52, 4004.528));

ft_printf("[%d]\n", ft_printf("|%-3.1f| |%5.2f| |%+1.0f| |%+0.2f|\n", 1004.52, 0004.52,  1004.525488, 2004.5203));
printf("[%d]\n", printf("|%-3.1f| |%5.2f| |%+1.0f| |%+0.2f|\n", 1004.52, 0004.52, 1004.525488, 2004.5203));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 1004.525, 3004.52, 1004.52, 9004.52, 7004.52));
printf("[%d]\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 1004.525, 3004.52, 1004.52, 9004.52, 7004.52));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 4004.52, 2004.52, 4004.52, 1004.52, 5004.52));
printf("[%d]\n", printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 4004.52, 2004.52, 4004.52, 1004.52, 5004.52));


ft_printf("%d\n", ft_printf("%f\n", 1455.2987876));
printf("%d\n", printf("%f\n", 1455.2987876));
printf("\n");
	ft_printf("%d\n", ft_printf("This is a float : %f\n", 45.236));
	printf("%d\n", printf("This is a float : %f\n", 45.236));
printf("\n");
	ft_printf("%d\n", ft_printf("This is a float : %.3f\n", 45.236));
	printf("%d\n", printf("This is a float : %.3f\n", 45.236));
printf("\n");
	ft_printf("%d\n", ft_printf("This is a float : %3f\n", 45.236));
	printf("%d\n",   printf("This is a float : %3f\n", 45.236));
printf("\n");
	ft_printf("%d\n", ft_printf("This is a float : %.3f\n", -45.236));
	printf("%d\n", printf("This is a float : %.3f\n", -45.236));
printf("\n");
	ft_printf("%d\n", ft_printf("This is a float : %f\n", 0.00025));
	printf("%d\n", printf("This is a float : %f\n", 0.00025));
printf("\n");
	ft_printf("%d\n", ft_printf("This is a float : %.3f\n", 0.00025));
	printf("%d\n", printf("This is a float : %.3f\n", 0.00025));
printf("\n");
	ft_printf("%d\n", ft_printf("This is a float : %3f\n", 0.00025));
	printf("%d\n", printf("This is a float : %3f\n", 0.00025));
printf("\n");
	ft_printf("%d\n", ft_printf("This is a float : %f\n", -0.00025));
	printf("%d\n", printf("This is a float : %f\n", -0.00025));
printf("\n");
	ft_printf("%d\n", ft_printf("This is a float : %.3f\n", -0.00025));
	printf("%d\n", printf("This is a float : %.3f\n", -0.00025));
printf("\n");
	ft_printf("%d\n", ft_printf("This is a float : %3f\n", -0.00025));
	printf("%d\n", printf("This is a float : %3f\n", -0.00025));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 50.2548, 50.2548, 50.2548, 50.2548, 50.2548));
printf("%d\n", printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 50.2548, 50.2548, 50.2548, 50.2548, 50.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%01.f| |%02.f| |%03.f| |%1.f| |%2.f|\n", -450.2548, 200.2548, 960000.2548, 20.2548, -10.2548));
printf("%d\n", printf("|%01.f| |%02.f| |%03.f| |%1.f| |%2.f|\n", -450.2548, 200.2548, 960000.2548, 20.2548, -10.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01.f| |%#02.f| |%03.f| |%1.f| |%2.f|\n", -450.2548, 200.2548, 960000.2548, 20.2548, -10.2548));
printf("%d\n", printf("|%#01.f| |%#02.f| |%03.f| |%1.f| |%2.f|\n", -450.2548, 200.2548, 960000.2548, 20.2548, -10.2548));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%-.1f| |%-.2f|\n", 50.2548, 50.2548));
printf("[%d]\n", printf("|%-.1f| |%-.2f|\n", 50.2548, 50.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%5.f| |%-.2f| |%-.1f| |%-.2f|\n", 00.00, 00.00, 00.00, 00.00));
printf("[%d]\n", printf("|%5.f| |%-.2f| |%-.1f| |%-.2f|\n", 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%#0-10f| |%#0+10f| |%#0+10.f| |%#0-10.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%#0-10f| |%#0+10f| |%#0+10.f| |%#0-10.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%-.2f| |%5.f| |%-5.f|\n", 50.2548, 00.00, 00.00));
printf("%d\n", printf("|%-.2f| |%5.f| |%-5.f|\n", 50.2548, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 150.2548, 3000.2548, 1400.2548, 90.2548, 70.2548));
printf("%d\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 150.2548, 3000.2548, 1400.2548, 90.2548, 70.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%-1.5f| |%+2.4f| |%-3.f| |%-1.f| |%-2.f|\n", 12.68999, -78.68999, 58.68999, 8.68999, 48.68999));
printf("%d\n", printf("|%-1.5f| |%+2.4f| |%-3.f| |%-1.f| |%-2.f|\n",  12.68999, -78.68999, 58.68999, 8.68999, 48.68999));
printf("\n");

ft_printf("%d\n", ft_printf("|%-3.1f| |%5.2f| |%+1.0f| |%+0.2f|\n", 1.68999, 0.68999, 15488.68999, 203.68999));
printf("%d\n", printf("|%-3.1f| |%5.2f| |%+1.0f| |%+0.2f|\n", 1.68999, 0.68999, 15488.68999, 203.68999));
printf("\n");

ft_printf("%d\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.68999, 3.68999, 1.68999, 9.68999, 7.68999));
printf("%d\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.68999, 3.68999, 1.68999, 9.68999, 7.68999));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 4.68999, 2.68999, 4.68999, 1.68999, 5.68999));
printf("%d\n", printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f| \n", 4.68999, 2.68999, 4.68999, 1.68999, 5.68999));
printf("\n");

ft_printf("%d\n", ft_printf("|%#0+10.f| |%#0-10.f| |%+1.0f| |%+0.2f|\n", 9.68999, 8.68999, 15.68999, .68999));
printf("%dn", printf("|%#0+10.f| |%#0-10.f| |%+1.0f| |%+0.2f|\n", 9.68999, 8.68999, 15.68999, 9.68999));
printf("\n");

ft_printf("%d\n", ft_printf("|% .10lf| |%-.10f| |%+.10f| |% .10f| |%- .5f|\n", 4950.2548, 250.2548, 450.2548, 150.2548, 550.2548));
printf("%d\n", printf("|% .10lf| |%-.10f| |%+.10f| |% .10f| |%- .5f|\n", 4950.2548, 250.2548, 450.2548, 150.2548, 550.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%10.lf| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 450.2548, 250.2548, 450.2548, 150.2548, 550.2548));
printf("%d\n", printf("|%10.lf| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 450.2548, 250.2548, 450.2548, 150.2548, 550.2548));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%5.f| |%-5.f| |%+ .5f| |%+ .10f|\n", 950.2548, 850.2548, 1550.2548, 1550.2548));
printf("[%d]\n", printf("|%5.f| |%-5.f| |%+ .5f| |%+ .10f|\n", 950.2548, 850.2548, 1550.2548, 1550.2548));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 550.2548, 550.2548, 550.2548, 550.2548, 550.2548));
printf("[%d]\n", printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 550.2548, 550.2548, 550.2548, 550.2548, 550.2548));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#01.f| |%#02.f| |%03.f| |%1.f| |%2.f|\n", -4550.2548, 2050.2548, 9600050.2548, 250.2548, -15099.27899));
printf("[%d]\n", printf("|%#01.f| |%#02.f| |%03.f| |%1.f| |%2.f|\n", -4550.2548, 2050.2548, 9600050.2548, 250.2548, -15099.27899));


ft_printf("[%d]\n", ft_printf("|%.1f| |%.2f| |%-.1f| |%-.2f|\n", 6050.2548, -4750.2548, 550.2548, 550.2548));
printf("[%d]\n", printf("|%.1f| |%.2f| |%-.1f| |%-.2f|\n", 6050.2548, -4750.2548, 550.2548, 550.2548));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("[%d]\n", printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("[%d]\n", printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%5.f| |%-.2f| |%-.1f| |%-.2f|\n", 00.00, 00.00, 00.00, 00.00));
printf("[%d]\n", printf("|%5.f| |%-.2f| |%-.1f| |%-.2f|\n", 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("[%d]\n", printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("[%d]\n", printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));

ft_printf("[%d]\n", ft_printf("|%#0+10.f| |%#0-10.f| |%5.f| |%-5.f|\n", 00.00, 00.00, 00.00, 00.00));
printf("[%d]\n", printf("|%#0+10.f| |%#0-10.f| |%5.f| |%-5.f|\n", 00.00, 00.00, 00.00, 00.00));

ft_printf("[%d]\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 1599.27899, 30099.27899, 14099.27899, 999.27899, 799.27899));
printf("[%d]\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 1599.27899, 30099.27899, 14099.27899, 999.27899, 799.27899));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%-1.5f| |%+2.4f| |%-3.f| |%-1.f| |%-2.f|\n", 12599.27899, -7899.27899, 5899.27899, 899.27899, 4899.27899));
printf("[%d]\n", printf("|%-1.5f| |%+2.4f| |%-3.f| |%-1.f| |%-2.f|\n",  12599.27899, -7899.27899, 5899.27899, 899.27899, 4899.27899));

ft_printf("[%d]\n", ft_printf("|%-3.1f| |%5.2f| |%+1.0f| |%+0.2f|\n", 199.27899, 099.27899, 1548899.27899, 20399.27899));
printf("[%d]\n", printf("|%-3.1f| |%5.2f| |%+1.0f| |%+0.2f|\n", 199.27899, 099.27899, 1548899.27899, 20399.27899));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.0, 3.0, 1.0, 9.0, 7.0));
printf("[%d]\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.0, 3.0, 1.0, 9.0, 7.0));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 499.27899, 299.27899, 499.27899, 199.27899, 599.27899));
printf("[%d]\n", printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 499.27899, 299.27899, 499.27899, 199.27899, 599.27899));

ft_printf("[%d]\n", ft_printf("|%#0+10.f| |%#0-10.f| |%+1.0f| |%+0.2f|\n", 999.27899, 899.27899, 1599.27899, 999.27899));
printf("[%d]\n", printf("|%#0+10.f| |%#0-10.f| |%+1.0f| |%+0.2f|\n", 999.27899, 899.27899, 1599.27899, 999.27899));
printf("\n");

ft_printf("[%d]\n", ft_printf("|% .10lf| |%-.10f| |%+.10f| |% .10f| |%- .5f|\n", 4.5, 2.5, 4.5, 1.5, 5.5));
printf("[%d]\n", printf("|% .10lf| |%-.10f| |%+.10f| |% .10f| |%- .5f|\n", 4.5, 2.5, 4.5, 1.5, 5.5));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%10.lf| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 4.5, 2.5, 4.5, 1.5, 5.5));
printf("[%d]\n", printf("|%10.lf| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 4.5, 2.5, 4.5, 1.5, 5.5));

ft_printf("[%d]\n", ft_printf("|%5.f| |%-5.f| |%+ .5f| |%+ .10f|\n", 9.010101, 8.010101, 9.010101, 8.010101));
printf("[%d]\n", printf("|%5.f| |%-5.f| |%+ .5f| |%+ .10f|\n", 9.010101, 8.010101, 9.010101, 8.010101));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%#0-10f| |%-.1f| |%-.2f|\n", 0.010101, 5.010101, 5.010101));
printf("[%d]\n", printf("|%#0-10f| |%-.1f| |%-.2f|\n", 0.010101, 5.010101, 5.010101));


ft_printf("[%d]\n", ft_printf("|% .f|\n", 00.00));
printf("[%d]\n", printf("|% .f|\n", 00.00));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%.f|\n", 00.00));
printf("[%d]\n", printf("|%.f|\n", 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 5489489.54621, 5489489.54621, 5489489.54621, 5489489.54621, 5489489.54621));
printf("%d\n", printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 5489489.54621, 5489489.54621, 5489489.54621, 5489489.54621, 5489489.54621));
printf("\n");

ft_printf("%d\n", ft_printf("|%01.f| |%02.f| |%03.f| |%1.f| |%2.f|\n", -45489489.54621, 20489489.54621, 96000489.54621, 2489489.54621, -1489489.54621));
printf("%d\n", printf("|%01.f| |%02.f| |%03.f| |%1.f| |%2.f|\n", -45489489.54621, 20489489.54621, 96000489.54621, 2489489.54621, -1489489.54621));
printf("\n");

ft_printf("%d\n", ft_printf("|%.1f| |%.2f| |%#.1f| |%#.2f|\n", 60489489.54621, -47489489.54621, 60489489.54621, -47489489.54621));
printf("%d\n", printf("|%.1f| |%.2f| |%#.1f| |%#.2f|\n", 60489489.54621, -47489489.54621, 60489489.54621, -47489489.54621));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01.f| |%#02.f| |%03.f| |%1.f| |%2.f|\n", -45489489.54621, 20489489.54621, 96000489.54621, 2489489.54621, -1489489.54621));
printf("%d\n", printf("|%#01.f| |%#02.f| |%03.f| |%1.f| |%2.f|\n", -45489489.54621, 20489489.54621, 96000489.54621, 2489489.54621, -1489489.54621));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%#01.f| |%02.f| |%-03.f| |%1.f| |%2.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%5.f| |%-.2f| |%-.1f| |%-.2f|\n", 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%5.f| |%-.2f| |%-.1f| |%-.2f|\n", 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 0, 0, 0, 0, 0.0));
printf("%d\n", printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 0, 0, 0, 0, 0.0));
printf("\n");

ft_printf("%d\n", ft_printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%10.f| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("-----|%#0+10.f| |%#0-10.f| |%5.f| |%-5.f|\n", 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("-----|%#0+10.f| |%#0-10.f| |%5.f| |%-5.f|\n", 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("%d\n", printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 00.00, 00.00, 00.00, 00.00, 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.2548, 300.2548, 140.2548, 9.2548, 7.2548));
printf("%d\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.2548, 300.2548, 140.2548, 9.2548, 7.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%-1.5f| |%+2.4f| |%-3.f| |%-1.f| |%-2.f|\n", 125.2548, -78.2548, 58.2548, 8.2548, 48.2548));
printf("%d\n", printf("|%-1.5f| |%+2.4f| |%-3.f| |%-1.f| |%-2.f|\n",  125.2548, -78.2548, 58.2548, 8.2548, 48.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%-3.1f| |%5.2f| |%+1.0f| |%+0.2f|\n", 1.2548, 0.2548, 15488.2548, 203.2548));
printf("%d\n", printf("|%-3.1f| |%5.2f| |%+1.0f| |%+0.2f|\n", 1.2548, 0.2548, 15488.2548, 203.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.2548, 3.2548, 1.2548, 9.2548, 7.2548));
printf("%d\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.2548, 3.2548, 1.2548, 9.2548, 7.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 4.2548, 2.2548, 4.2548, 1.2548, 5.2548));
printf("%d\n", printf("|%#01f| |%#0.10f| |%#010f| |%#0-10f| |%#0+10f|\n", 4.2548, 2.2548, 4.2548, 1.2548, 5.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%#0+10.f| |%#0-10.f| |%+1.0f| |%+0.2f|\n", 9.2548, 8.2548, 15.2548, 19.2548));
printf("%d\n", printf("|%#0+10.f| |%#0-10.f| |%+1.0f| |%+0.2f|\n", 9.2548, 8.2548, 15.2548, 19.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%#0+10.f|\n", 00.00));
printf("%d\n", printf("|%#0+10.f|\n", 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%01.f|\n", -45.54));
printf("%d\n", printf("|%01.f|\n", -45.54));
printf("\n");

ft_printf("%d\n", ft_printf("|% .10lf| |%-.10f| |%+.10f| |% .10f| |%- .5f|\n", 4.2548, 2.2548, 4.2548, 1.2548, 5.2548));
printf("%d\n", printf("|% .10lf| |%-.10f| |%+.10f| |% .10f| |%- .5f|\n", 4.2548, 2.2548, 4.2548, 1.2548, 5.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%10.lf| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 4.2548, 2.2548, 4.2548, 1.2548, 5.2548));
printf("%d\n", printf("|%10.lf| |%-10.f| |%10.f| |%10.f| |%-10.f|\n", 4.2548, 2.2548, 4.2548, 1.2548, 5.2548));
printf("\n");

ft_printf("%d\n", ft_printf("|%5.f| |%-5.f| |%+ .5f| |%+ .10f|\n", 9.9, 8.9, 9.9, 8.9));
printf("%d\n", printf("|%5.f| |%-5.f| |%+ .5f| |%+ .10f|\n", 9.9, 8.9, 9.9, 8.9));
printf("\n");

ft_printf("%d\n", ft_printf("|%1f|\n", 00.00));
printf("%d\n", printf("|%1f|\n", 00.00));
printf("\n");

ft_printf("%d\n", ft_printf("|%04.2f| |%#2f| et |%#-8.3f|\n", 154896.25847856, 154896.25847856, 154896.25847856));
printf("%d\n", printf("|%04.2f| |%#2f| et |%#-8.3f|\n", 154896.25847856, 154896.25847856, 154896.25847856));
printf("\n");

ft_printf("[%d]\n", ft_printf("|%.3f| |%+2.4f|\n", 0.0, -7004.528));
printf("[%d]\n", printf("|%.3f| |%+2.4f|\n", 0.0, -7004.528));

printf("\n");
ft_printf("[%d]\n", ft_printf("This is a float : %f\n", -45.236));
printf("[%d]\n", printf("This is a float : %f\n", -45.236));

printf("\n");
ft_printf("%d\n", ft_printf("This is a float : %3f\n", -45.236));
printf("%d\n", printf("This is a float : %3f\n", -45.236));
printf("\n");
ft_printf("%d\n", ft_printf("|%01.f|\n", -46.54));
printf("%d\n", printf("|%01.f|\n", -46.54));
printf("\n");
ft_printf("%d\n", ft_printf("|%f|\n", NULL));
printf("%d\n", printf("|%f|\n", NULL));
printf("\n");

ft_printf("%d\n", ft_printf("|%f|\n", 0));
printf("%d\n", printf("|%f|\n", 0));
printf("\n");
ft_printf("%d\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.2548, 3.2548, 1.2548, 9.2548, 7.2548));
printf("%d\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 15.2548, 3.2548, 1.2548, 9.2548, 7.2548));
printf("\n");
ft_printf("%d\n", ft_printf("|%.f.| |%.f.|\n", 7.5, 8.5));
printf("%d\n", printf("|%.f.| |%.f.|\n", 7.5, 8.5));
printf("\n");
ft_printf("%d\n", ft_printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 0.0, 0.0, 0.0, 0.0, 0.0));
printf("%d\n", printf("|%1.f| |%.1f| |%-1.f| |%-.1f| |%.3f|\n", 0.0, 0.0, 0.0, 0.0, 0.0));
printf("\n");
ft_printf("[%d]\n", ft_printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 16.0, 3.0, 1.0, 9.0, 7.0));
printf("[%d]\n", printf("|%+1.1f| |%+2.0f| |%+3.1f| |%+1.0f| |%+2.1f|\n", 16.0, 3.0, 1.0, 9.0, 7.0));
printf("\n");


//printf ("\nd = %d\n\n", (int)ft_pow10(0.58796321, 6));

	ft_printf("\n|%+f|\n", -0.0);
	printf("|%+f|\n", -0.0);
	return (0);
}