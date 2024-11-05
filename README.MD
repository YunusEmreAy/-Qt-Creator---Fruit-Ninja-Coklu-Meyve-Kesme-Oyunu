# Çoklu Meyve Kesme Oyunu

Fruit Ninja'dan esinlenilmiş, **Qt Creator** ve **C++** kullanılarak geliştirilen dinamik ve heyecan verici bir meyve kesme oyunu. Oyun, çeşitli meyve türleri ve üç farklı arka plan seçeneği sunarak oyunculara eğlenceli ve görsel olarak etkileyici bir deneyim sunar.

## Proje Genel Bakış

Bu meyve kesme oyunu, oyuncuları 30 saniyelik süre içinde olabildiğince çok meyveyi kesmeye davet ediyor. Oyun, farklı meyve türleri ve arka plan değiştirme özelliği ile zenginleştirilmiştir, bu da oyunu daha keyifli hale getiriyor.

## Temel Özellikler

- **Çeşitli Meyveler**: 
  - Oyun; **karpuz**, **ananas**, **elma**, **hindistancevizi**, **limon** ve **portakal** gibi çeşitli meyveleri içerir.
  - Her meyve rastgele pozisyonlarda ekrana gelir ve oyuncu, meyveleri kesmek için tıklamalıdır.
- **Rastgele Pozisyonlandırma**: 
  - Meyve koordinatları `konumlar.txt` dosyasından okunur, bu da meyvelerin ekranda rastgele belirmesini sağlar.
- **Özelleştirilebilir Arka Planlar**:
  - Oyuncular, üç farklı arka plan arasından seçim yaparak oyun ortamını değiştirebilir.
- **Etkileşimli Oynanış**: 
  - Bir meyveye tıklanıldığında kesme animasyonu tetiklenir ve meyve kısa bir süre sonra yok olur.
- **Performans Takibi**:
  - Oyun sonunda, kesilen ve kaçırılan meyve sayısı ile toplam skor görüntülenir.
  - Skor `skorlar.txt` dosyasına kaydedilir ve oyuncuya en yüksek skoru geçip geçmediği bilgisi verilir.
- **30 Saniyelik Zamanlayıcı**: 
  - Oyun 30 saniye sürer ve oyuncular bu süre içinde olabildiğince çok meyve kesmeye çalışır.
- **Ek Özellikler**:
  - **Özel Oynanış Geliştirmesi**: Kod içerisinde, örneğin kullanıcı ayarlarını özelleştirme gibi ek özellikler sunulmuştur. Bu özellikler `dialog.cpp` dosyasında detaylı olarak açıklanmıştır.
  - Oyun arayüzü, kullanıcının ekran boyutuna göre dinamik olarak ayarlanır ve arka plan belirli bir Y-koordinatından başlar.

## Dosyalar ve Yapı

- **main.cpp**: Uygulamanın ana giriş noktası.
- **dialog.cpp / dialog.h / dialog.ui**: 
  - Oyunun arayüzünü, meyve oluşturmayı, animasyonları, arka plan ayarlarını ve kullanıcı etkileşimlerini yönetir.
  - Oyunun mekaniklerini ve ek özellikleri anlamak için iyi bir şekilde belgelenmiştir.
- **konumlar.txt**: Meyvelerin ekranda belireceği koordinatları içeren bir metin dosyası.
- **skorlar.txt**: Oyuncunun önceki oyunlardan elde ettiği skorları saklar.
- **resource.qrc**: Meyve ve arka plan görselleri gibi oyun kaynaklarını yönetir.

## Detaylı Oynanış Talimatları

1. **Oyunu Başlatma**: 
   - Oyunu **Qt Creator** üzerinden çalıştırın ve ekranda beliren meyveleri kesmeye başlayın.
2. **Meyve Kesme**: 
   - Meyveleri kesmek için üzerine tıklayın. Farklı meyveler, `konumlar.txt` dosyasında tanımlanan koordinatlara göre rastgele belirecektir.
3. **Arka Plan Değiştirme**:
   - Oyun arayüzünden üç farklı arka plan seçeneği arasından seçim yapabilirsiniz.
4. **Skor Takibi**: 
   - Oyun sonunda, kesilen ve kaçırılan meyve sayısı ile skor görüntülenir. En yüksek skoru geçip geçmediğiniz `skorlar.txt` dosyasında takip edilir.

## Nasıl Derlenir ve Çalıştırılır

1. **Qt Creator** üzerinden projeyi açın.
2. Gerekli yapılandırmaları yapın.
3. **Derleyin ve çalıştırın**.
4. Meyveleri kesmenin keyfini çıkarın ve en yüksek skoru elde etmeye çalışın!

## Ek Notlar

- Oyunun kodu, her özelliğin oynanışı nasıl geliştirdiğine dair açıklamalar içerecek şekilde iyi bir şekilde belgelenmiştir.
- Gerekli kaynakların `resource.qrc` dosyasında doğru bir şekilde referans verildiğinden emin olun.
- Proje, performans ve kullanıcı deneyimi için optimize edilmiştir.

Kodları inceleyebilir ve oyunu istediğiniz gibi özelleştirebilirsiniz. Meyve kesmenin tadını çıkarın ve en yüksek skora ulaşın!

