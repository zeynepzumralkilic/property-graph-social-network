# property-graph-social-network
Veri Yapıları Projesi


## Proje Açıklaması
Bu projede sosyal ağ sistemlerinde kullanılan property graph veri modelinin sadeleştirilmiş bir versiyonu geliştirilmektedir.

## Amaç
Kullanıcılar, fotoğraflar ve etkinlikler gibi varlıkların düğümler olarak; arkadaşlık, beğeni ve katılım gibi ilişkilerin kenarlar olarak modellenmesi hedeflenmektedir.

## Yapılan Çalışmalar (Ara Rapor)
- Temel graph yapısı oluşturuldu
- Vertex ve edge yapıları tanımlandı
- Kullanıcı ekleme fonksiyonu geliştirildi
- Arkadaşlık ilişkisi eklendi
- BFS algoritması üzerinde çalışıldı

 ##  Ekip Üyeleri ve Görev Dağılımı

Bu proje 5 kişilik bir ekip tarafından geliştirilmiştir. Her ekip üyesi belirli bir modülden sorumlu olup, geliştirmelerini kendi branch’i üzerinden gerçekleştirmiştir.

| İsim | Görev | Branch |
|------|------|--------|
| Zeynep Zümral Kılıç | Graph Core (Property Graph yapısı ve adjacency list implementasyonu) | graph-core |
| Onur Saylan | Node & Property Sistemi (Vertex yapısı ve özellikler) | vertex-properties |
| İsmail Kerem Tuna | Hash Table (Düğümlerin O(1) erişimi) | hash-table |
| Aleyna Tokgöz | Algoritmalar (BFS, DFS ve traversal işlemleri) | algorithms |
| Yekta Ağra | Sorgu Sistemi (Çok adımlı sorgular ve kullanıcı etkileşimi) | query-system |

---

##  Çalışma Süreci

- Her ekip üyesi kendi branch’inde geliştirme yapmıştır.
- Yapılan geliştirmeler **pull request (PR)** yöntemiyle ana (main) branch’e aktarılmıştır.
- Commit geçmişi üzerinden tüm katkılar izlenebilmektedir.
- Proje modüler bir yapıda geliştirilmiştir.

---

##  Kullanılan Yapılar

- Property Graph (Vertex + Edge + Properties)
- Adjacency List
- Hash Table
- BFS ve DFS algoritmaları
- Çok adımlı sorgu sistemi

