 Выведи мне топ 5 файлов, в которых чаще всего встречается слово pizza
 grep pizza *.* | sort | uniq -c | sort -r
