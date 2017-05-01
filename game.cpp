#include "game.h"

/*
 * Конструктор класса Game по умолчанию
*/
Game::Game()
{
    if (!db.isOpen())
        connectDB();

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
}

/*
 * Деструктор класса Game
*/
Game::~Game()
{
    if (db.isOpen())
        db.close();
}

/*
 * Функция возвращает объект класса Player
*/
Player Game::getPlayer() const
{
    return player;
}

/*
 * Функция изменяет текущего игрока
 * Переменные:
 * @value - новый игрок
*/
void Game::setPlayer(const Player &value)
{
    player = value;
}

/* Функция производит логин пользователя.
 * Взвращает true, если пароль правильный, и
 * false, если неправильный.
 * Переменные:
 * @name - имя пользователя
 * @pass - пароль
*/
bool Game::login(QString name, QString pass)
{
    if (!db.isOpen()){
        connectDB();
    }
    QSqlQuery query = getUserFromDB(name);
    QString l;
    QString p;
    int ms;
    int fs;
    QString t;

    while (query.next()) {
        l = query.value(0).toString();
        p = query.value(1).toString();
        ms = query.value(2).toInt();
        fs = query.value(3).toInt();
        t = query.value(4).toString();
    }
    if (p == pass)
    {
        Player p(name, ms, fs, t);
        player = p;

        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Функция для разлогинивания пользователя
*/
void Game::logout()
{
    Player p;
    player = p;
}

/*
 * Функция регистрирует пользователя в игре и логинит его
 * Взвращает true, если пользователя с таким логном нет, и
 * false, если есть.
 * Параметры:
 * @name - имя пользователя
 * @pass - пароль
*/
bool Game::signup(QString name, QString pass)
{
    if (!db.isOpen()){
        connectDB();
    }
    QSqlQuery query_check = getUserFromDB(name);

    int ms = player.getMusicScore();
    int fs = player.getFilmScore();

    query_check.next();
    QString n = query_check.value(0).toString();
    if (n == "" && name != "Player"){
        QSqlQuery query;
        query.prepare("INSERT INTO players (login, password, music_score, film_score, type)"
                      "VALUES(?, ?, ?, ?, ?);");
        query.addBindValue(name);
        query.addBindValue(pass);
        query.addBindValue(ms);
        query.addBindValue(fs);
        query.addBindValue("user");
        query.exec();

        Player p(name, ms, fs, "user");
        player = p;
        return true;
    }
    else {
        return false;
    }

}

/*
 * Функция проверяет залогинен ли сейчас какой-либо пользователь
*/
bool Game::isLogin()
{
    if (player.getName() != "Player"){
        return true;
    }
    else {
        return false;
    }
}
/*
 * Функция получения данных пользователя из БД.
 * Переменные:
 * @username - логин пользователя
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

/*
 * Функция получения общей статистики из БД
*/
QSqlQuery Game::getStats()
{
    if (!db.isOpen())
        connectDB();
    QSqlQuery query("SELECT login, music_score, film_score, (music_score+film_score) as total "
                    "FROM players "
                    "ORDER BY total DESC");
    return query;
}

/*
 * Функция для установки соединения с БД
*/
void Game::connectDB()
{
    if (!db.isOpen())
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(QApplication::applicationDirPath()+"/../../gui-1h2017-14/db/database.db");
        db.open();
    }
}

/*
 * Функция запуска игрового процесса
 * Переменные:
 * @type - тип игры
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

/* Функция получения названия для варианта ответа
 * Переменные:
 * @type - тип игры
 * @id - номер кнопки
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

/*
 * Функция получения названия для правильного варианта ответа
 * Переменные:
 * @type - тип игры
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

/*
 * Функция для проверки ответа пользователя
 * Переменные:
 * @type - тип игры
 * @id - номер кнопки ответа
*/
bool Game::checkAnswerId(QString type, int id)
{
    if (type == "music"){
        return gameMusic.checkAnswer(id);
    }
    else
    {
        return false;//
    }
}

/*
 * Функция для перезапуска игры при выходе на главный экран
 * Переменные:
 * @type - тип игры
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

/*
 * Функция для получения рандомной песни для фона
*/
QString Game::playBkgdMusic()
{
    return gameMusic.backgroundMusic();
}
