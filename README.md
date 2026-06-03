# Property Graph Based Social Network Analysis System

## Proje Tanımı

Bu projede, sosyal medya benzeri bir ağ yapısının Property Graph modeli kullanılarak temsil edilmesi, sorgulanması ve görselleştirilmesi amaçlanmıştır. Sistem; kullanıcılar, fotoğraflar ve etkinlikler gibi farklı düğüm türlerini desteklemekte, düğümler arasındaki ilişkileri yönlü kenarlar ile modellemektedir.

Proje kapsamında temel veri yapıları ve grafik algoritmaları kullanılarak sosyal ağ analizleri gerçekleştirilmiştir.

---

# Sistem Mimarisi

Sistem üç ana katmandan oluşmaktadır:

## 1. Frontend (Raylib GUI)

Frontend katmanı Raylib kütüphanesi kullanılarak geliştirilmiştir.

Görevleri:

* Graf düğümlerini görselleştirmek
* Düğümler arasındaki ilişkileri göstermek
* Kullanıcının sorgu çalıştırmasını sağlamak
* Düğüm detaylarını görüntülemek
* BFS, DFS ve sosyal ağ sorgularının sonuçlarını göstermek

Düğüm türleri:

* User → Daire
* Photo → Kare
* Event → Üçgen

---

## 2. Backend (Graph Engine)

Backend katmanında temel veri yapıları ve algoritmalar yer almaktadır.

Bileşenler:

* Graph
* Hash Table
* Trie
* Queue

Bu katman sosyal ağ verilerinin tutulması ve işlenmesinden sorumludur.

---

## 3. AI Service

AI servisi Python Flask kullanılarak geliştirilmiştir.

Görevleri:

* Doğal dil sorgularını yorumlamak
* Kullanıcı sorgularını yapılandırılmış sorgulara dönüştürmek
* Backend katmanına uygun sorgu tiplerini üretmek

Örnek:

"Find friends of user 1"

↓

FRIENDS_QUERY(UserID=1)

---

# Kullanılan Veri Yapıları

## Graph

Graf yapısı sistemin temel veri modelidir.

Her düğüm:

* User
* Photo
* Event

olabilir.

İlişki türleri:

* FRIEND
* LIKES
* ATTENDS

Graph adjacency list yaklaşımı ile gerçekleştirilmiştir.

---

## Hash Table

Hash Table düğümlere hızlı erişim sağlamak amacıyla kullanılmıştır.

Kullanım alanları:

* Node arama
* Özellik görüntüleme
* Kimlik bazlı erişim

Ortalama erişim karmaşıklığı:

O(1)

---

## Trie

Trie yapısı isim bazlı aramalarda kullanılmaktadır.

Kullanım alanları:

* Kullanıcı adı arama
* Otomatik tamamlama
* Prefix tabanlı sorgular

Arama karmaşıklığı:

O(L)

L = kelime uzunluğu

---

## Queue

Queue veri yapısı BFS algoritmasında kullanılmıştır.

İşlemler:

* Enqueue
* Dequeue
* IsEmpty

---

# Gerçekleştirilen Algoritmalar

## BFS (Breadth First Search)

Graf üzerinde genişlik öncelikli dolaşma gerçekleştirir.

Kullanım alanları:

* Arkadaş önerileri
* Sosyal ağ analizi
* Bağlantı keşfi

Zaman karmaşıklığı:

O(V + E)

---

## DFS (Depth First Search)

Graf üzerinde derinlik öncelikli dolaşma gerçekleştirir.

Kullanım alanları:

* Bağlantı analizi
* Alt ağ keşfi
* Graf gezme işlemleri

Zaman karmaşıklığı:

O(V + E)

---

## Shortest Path

İki düğüm arasındaki en kısa bağlantının bulunmasını sağlar.

Kullanım alanları:

* Degrees of Separation
* Kullanıcı bağlantı analizi

---

## Social Query

Özel sosyal ağ sorgularının gerçekleştirilmesi için geliştirilmiştir.

Örnek:

* Kullanıcının arkadaşları
* Beğendiği fotoğraflar
* Katıldığı etkinlikler

---

# UML Bileşenleri

Node
│
├── User
├── Photo
└── Event

Graph
│
├── Node List
└── Edge List

HashTable
│
└── Node Lookup

Trie
│
└── Text Search

Queue
│
└── BFS Operations

Algorithms
│
├── BFS
├── DFS
├── Shortest Path
└── Social Query

Frontend GUI
│
└── Visualization Layer

AI Service
│
└── Query Interpreter

---

# Docker Yapısı

Proje Docker ortamında çalıştırılabilecek şekilde tasarlanmıştır.

Bileşenler:

* Frontend Container
* Backend Container
* AI Service Container

Sistem aşağıdaki komut ile ayağa kaldırılabilir:

docker compose up

---

# Derleme

Frontend:

g++ -std=c++11 gui.cpp -lraylib

Backend:

gcc main.c graph.c hash.c queue.c trie.c algorithms.c -o main

AI Service:

python app.py

---
# Big-O Karmaşıklık Analizi

| Veri Yapısı / Algoritma     | İşlem                   | Zaman Karmaşıklığı |
| --------------------------- | ----------------------- | ------------------ |
| Graph (Adjacency List)      | Düğüm Ekleme            | O(1)               |
| Graph (Adjacency List)      | Kenar Ekleme            | O(1)               |
| Graph                       | Düğüm Arama             | O(V)               |
| Graph                       | Kenar Arama             | O(E)               |
| Hash Table                  | Ekleme                  | O(1) Ortalama      |
| Hash Table                  | Arama                   | O(1) Ortalama      |
| Hash Table                  | Silme                   | O(1) Ortalama      |
| Trie                        | Kelime Ekleme           | O(L)               |
| Trie                        | Kelime Arama            | O(L)               |
| Trie                        | Prefix Arama            | O(L)               |
| Queue                       | Enqueue                 | O(1)               |
| Queue                       | Dequeue                 | O(1)               |
| Queue                       | IsEmpty                 | O(1)               |
| BFS                         | Graf Taraması           | O(V + E)           |
| DFS                         | Graf Taraması           | O(V + E)           |
| Shortest Path (BFS Tabanlı) | Yol Bulma               | O(V + E)           |
| Degrees of Separation       | Mesafe Hesaplama        | O(V + E)           |
| Social Query                | Düğüm ve İlişki Analizi | O(V + E)           |

## Semboller

* V : Düğüm (Vertex) sayısı
* E : Kenar (Edge) sayısı
* L : Aranan kelimenin uzunluğu

## Değerlendirme

Sistemde hızlı düğüm erişimi sağlamak amacıyla Hash Table kullanılmıştır. Bu sayede düğüm özelliklerine ortalama O(1) zamanda erişilebilmektedir.

Trie veri yapısı, kullanıcı adı ve metin tabanlı aramalarda O(L) karmaşıklık sunarak verimli bir arama mekanizması sağlamaktadır.

Graf algoritmaları olan BFS ve DFS, tüm düğüm ve kenarları en fazla bir kez ziyaret ettiği için O(V + E) karmaşıklığında çalışmaktadır.

Queue veri yapısı BFS algoritmasının temelini oluşturmakta olup ekleme ve çıkarma işlemleri sabit zamanda gerçekleştirilmektedir.

# Sonuç

Bu projede Property Graph yaklaşımı kullanılarak sosyal ağ verilerinin modellenmesi, sorgulanması ve görselleştirilmesi başarıyla gerçekleştirilmiştir. Graph, Hash Table, Trie ve Queue gibi temel veri yapıları kullanılmış; BFS, DFS ve Shortest Path algoritmaları uygulanmıştır. Raylib tabanlı kullanıcı arayüzü sayesinde grafik yapı görselleştirilmiş ve kullanıcı etkileşimi sağlanmıştır.


