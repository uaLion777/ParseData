#pragma once
class ParseData
{
private:
	char buff[6]; // временный массив данных 

public:
	 unsigned short int data[16]; // массив с записанными данными
	 
	
	void parseData(String strData)
	{
		const char* startingTemplate = "data:"; // стартовый шаблон для начала поиска
		
		char 
			separatorData = ',',
			endData = ';'; // разделитель и конец приема данных

		uint8_t 
			nIndxData = 0, 
			nIndxBuff = 0,
			i = 0,
			j = 0;
		
		bool
			find = false;

		while (strData[i] != '\0')
		{

			

			if (find == true) // пишем данные в массив
			{
				if (strData[i] == separatorData) // если найден разделитель, то переходим к записи в следующий массив
				{
					buff[nIndxBuff] = '\0';
					data[nIndxData++] = atoi(buff); // преобразовуем из символьной строки число и пишем массив
					nIndxBuff = 0; // очищаем буффер для новой записи
				}
				else if (strData[i] == endData || strData[i] == '\r' || strData[i] == '\n')
				{
					buff[nIndxBuff] = '\0';
					data[nIndxData] = atoi(buff);
					break; // если найден конец приема данных, завершаем прием
				}
				
				else buff[nIndxBuff++] = strData[i];
			
			}
			else if (strData[i] == startingTemplate[j] && find != true) // ищем стартовый шаблон для разбора данных
			{

				if (strlen(startingTemplate) - 1 == j)
				{
					find = true; // высталяем флаг если весь шаблон найден и начинаем прием данных
				}
				j++; // проверяем следующий символ на совпадение в шаблоне

			}
			else j = 0; // если совпадение не полностью ищем сначала подстроку

			i++; // переходим к следующему символу
		}
	}
};