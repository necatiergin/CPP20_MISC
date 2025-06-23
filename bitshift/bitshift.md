#### C++20 ÖNCESİ DURUM
Negatif bir tam sayı üzerinde bitsel sola kaydır (<<) işlemi yapmak tanımsız davranış _(undefined behavior)_ idi. Neden? <br>
Çünkü C++ standardı (C++17 ve öncesi), << operatörüyle yapılan kaydırmanın yalnızca pozitif işaretli değerler veya işaretsiz değerler için tanımlı olduğunu belirtir. 
Eğer operand işaretli ve negatif değerde ise tanımsız davranış söz konusuydu.

```cpp
int x = -1;
int y = x << 1; // UB (C++17)
```

Bu davranışa ilişkin kurallar, C standardındaki 6.5.7 maddesinden miras alınmıştır.

#### C++20 İLE GETİRİLEN DEĞİŞİKLİK
C++20 standardı ile, bitwise sola kaydırma işlemi için daha net ve tanımlı kurallar getirildi. Artık işaretli bir değerin sola kaydırılması, aşağıdaki koşullar sağlandığında tanımlıdır: <br>

 ```
E1 << E2
```
- Operandın değeri E1 signed olmalı.
- E2 pozitif olmalı ve işlemin yapılacağı türünün bit genişliği kadar küçük olmalı.
- Sonuç, türün temsil edebileceği aralıkta kalmalı.

Eğer sonuç temsil edilemeyen bir değere dönüşürse hâlâ tanımsız davranış olabilir.

```
int x = -4;
int y = x << 1; // C++20 itibarıyla tanımlı, sonuç -8 (undefined değil)
```
Ancak derleyici, bu durumda yine de overflow olup olmadığını kontrol eder. Eğer sonucu int türüyle ifade etmek mümkün değilse, bu hâlâ UB olabilir.

📌 C++20 [expr.shift] Maddesi
Yeni standardın [expr.shift] bölümünde şu ifadeler yer alır:

"If E1 has a signed type and non-negative value, and E2 is non-negative and less than the width of the promoted E1, the behavior is defined. Otherwise, the behavior is implementation-defined or undefined."

Ancak C++20 ile bu ifadeler genişletilmiş, negatif operandların shift işlemiyle daha uyumlu hale getirilmesi amaçlanmıştır.
