# Process-Management-with-C-Programming-in-LINUX
Process Management with C Programming in LINUX. The same project has been created using the queue.

Part 1.
Bu partın kodu findtopk.c dosyasında bulunmaktadır. 

Ana process’in yanı sıra N adet child process oluşturabilecek bir program tasarlayınız.
N adet child process ile içerisinde birçok integer sayı bulunan N adet dosya içerisindeki k. en büyük sayıyı buldurma işlemi yapılacaktır. N adet girdi dosyası aynı anda N işlem tarafından işlenecektir. Her bir girdi dosyası çok büyük sayıda pozitif integer değerler içerebilir. Output dosyasına yazılacak olan sonuçlar büyükten küçüğe doğru sıralanmış olacaktır. K 1 ile 1000 arasında bir sayı olabilir. N değeri 1 ve 5 arasında bir sayı olabilir. Input ve output dosyaları ASCII text dosyaları olacaktır. Program aşağıdaki şekilde çağrılacaktır:
findtopk <k> <N> <infile1> ...<infileN> <outfile>
Her bir child process bir adet input dosyasını okuyacak ve işleyecektir. İşlenen dosyası intermediate (ara) dosyaya yazacaktır. Tüm child işlemler bittiği zaman ana process bu intermediate dosyaları okuyup işleyecektir. Normalde dosyaları okumak ve yazmak için fscanf ve fprintf kullanabilirdiniz. Fakat bu projede low-level I/O komutları olan read() ve write() kullanılacaktır. Bu sayede low-level I/O işlemlerinde pratik yapabilirsiniz. Dosyaları açmak ve kapatmak için open() ve close() fonksiyonlarını kullanabilirsiniz. Her seferinde yalnızca bir girdi dosyasında bir (veya çok az) karakter okuyabilirsiniz. İnput dosyaları içerisinde boşluk karakterleri ile (space,tab,newline) ile ayrılmış sayılar içermektedir. Output dosyasında her bir satırda yalnızca bir integer değer olmalıdır. Tüm işlemler bittiğinde processler sonlandığında program, intermediate dosyaları silmelidir.

Part 2. 
Bu partın kodu findtopk_mqueue.c dosyasında bulunmaktadır. 
Aynı projeyi, child processlerdeki bilgileri parent processlere aktarırken message queues kullanarak yapınız. Intermediate dosyalar kullanılmayacaktır. Bu durumda programın adı findtopk_mqueue olacaktır. 

