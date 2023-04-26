# HomeWorkSF
Напишите программу, которая сможет считывать из файла при своей загрузке и записывать в файл состояния 
объектов классов User и Message (для каждого класса свой файл):

class User {
    string _name;
    string _login;
    string _pass;
};
class Message {
    string _text;
    string _sender;
    string _receiver;
};

Сделайте это таким образом, чтобы файлы были недоступны для других пользователей, то есть 
чтобы  прочитать или записать информацию в файлы мог бы только пользователь, 
который запускает программу. 