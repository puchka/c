#include <QCoreApplication>
#include <QtSql>
#include <iostream>

#define q2c(string) string.toStdString()

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    std::cout << std::flush;
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("bdd");
	if(db.open())
	{
		std::cout << "Vous �tes maintenant connect�." << std::endl;
		QSqlQuery query;
		if (query.exec("create table saints (d int, m int, sex varchar(1), saint varchar(50))"))
		{
			std::cout << "La requ�te a r�ussi." << std::endl;
		}
		/*
		if (query.exec("create table events (d int, m int, event varchar(50))"))
		{
			std::cout << "La requ�te a r�ussi." << std::endl;
		}
		if (query.exec("create table todolist (d int, m int, y int, h int, "
					   "todo varchar(50))"))
		{
			std::cout << "La requ�te a r�ussi." << std::endl;
		}
		/*
		if (query.exec("SELECT * FROM events"))
		{
			while(query.next())
			{
				std::cout << " Nouvelle entr�e" << std::endl;
				for(int x=0; x < query.record().count(); ++x)
				{
					std::cout << " " << q2c(query.record().fieldName(x)) <<
					" = " << q2c(query.value(x).toString()) << std::endl;
				}
			}
		}
		*/
		else
			std::cout << "La requ�te a �chou�." << std::endl;
		db.close();
	}
	else
	{
		std::cout << "La connexion a �chou�e, d�sol�." << std::endl;
	}
    return app.exec();
}
