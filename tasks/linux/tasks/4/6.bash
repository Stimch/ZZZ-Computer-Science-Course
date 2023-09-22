 Найдите все py файлы, содержащие в названии любое из трёх слов: backdoor, trojan, keylogger.
 find -type f -iname "*backdoor*.py" -o -iname "*trojan*.py" -o -iname "*keylogger*.py"
