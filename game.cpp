#include "game.h"

/*Конструктор класса Game по умолчанию*/
Game::Game()
{
    if (!db.isOpen())
        connectDB();

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
}

/*Деструктор класса Game*/
Game::~Game()
{
    if (db.isOpen())
        db.close();
}

/*Функция возвращает объект Игрок*/
Player Game::getPlayer() const
{
    return player;
}

/*???*/
void Game::setPlayer(const Player &value)
{
    player = value;
}

/*Функция производит логин пользователя.
Переменные:
@name - имя пользователя
@ms - счет в игре Музыка
@fs - счет в игре Фильмы
@t - тип пользователя
*/
void Game::login(QString name, int ms, int fs, QString t)
{
    Player p(name, ms, fs, t);
    player = p;
}

/*Функция для разлогинивания пользователя*/
QString Game::logout()
{
    QString str;
    return str;
}

/*???*/
QString Game::signin(QString name, QString pass)
{
    QString str = name;
    return str = pass;
}

/*Функция получения данных пользователя из БД.
Переменные:
@username - логин пользователя
*/
QSqlQuery Game::getUserFromDB(QString username)
{
    if (!db.isOpen())
        connectDB();
    QSqlQuery query("SELECT login, password, music_score, film_score, type "
                    "FROM players "
                    "WHERE login IS \"" + username + "\"");
    return query;
}

/*Функция получения общей статистики из БД*/
QSqlQuery Game::getStats()
{
    if (!db.isOpen())
        connectDB();
    QSqlQuery query("SELECT login, music_score, film_score, (music_score+film_score) as total "
                    "FROM players "
                    "ORDER BY total DESC");
    return query;
}

/*Функция для установки соединения с БД*/
void Game::connectDB()
{
    if (!db.isOpen())
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(QApplication::applicationDirPath()+"/../../gui-1h2017-14/db/database.db");
        db.open();
    }
}

/*Функция запуска игрового процесса
Переменные:
@type - тип игры
*/
bool Game::playGame(QString type)
{
    if (type == "music"){
        return gameMusic.play();
    }
    else
    {
        return gameMusic.play();
    }
}

/*Функция получения названия для варианта ответа
Переменные:
@type - тип игры
@id - номер кнопки
*/
QString Game::getAnswer(QString type, int id)
{
    if (type == "music"){
        return gameMusic.getRandomAnsName(type, id-1);
    }
    else
    {
        return 0;
    }
}

/*Функция получения названия для правильного варианта ответа
Переменные:
@type - тип игры
*/
QString Game::getRightAnswerId(QString type)
{
    if (type == "music"){
        return gameMusic.getRightAnswerId();
    }
    else
    {
        return 0;
    }
}

/*Функция для проверки ответа пользователя
Переменные:
@type - тип игры
@id - номер кнопки ответа
*/
bool Game::checkAnswerId(QString type, int id)
{
    if (type == "music"){
        return gameMusic.answerCheck(id);
    }
    else
    {
        return false;//
    }
}

/*Функция для перезапуска игры при выходе на главный экран
Переменные:
@type - тип игры
*/
void Game::eraseContent(QString type)
{
    if (type == "music"){
        gameMusic.erase();
    }
    else
    {
        //gameMusic.erase();
    }
}

/*Функция для получения рандомной песни для фона*/
QString Game::bckgMusic()
{
    return gameMusic.backgroundMusic();
}
