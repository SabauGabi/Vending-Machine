# 🥤 Vending Machine Management System (C++)

## 📝 Descriere
Acest proiect este un simulator de **Vending Machine** dezvoltat în C++, realizat în cadrul laboratorului de Programare Orientată Obiect (UBB). Aplicația gestionează fluxul complet al unui automat: de la inventarul de produse (dulciuri, băuturi) până la logica complexă de acceptare a banilor și calculare a restului.

Obiectivul principal a fost implementarea unei **arhitecturi stratificate** și utilizarea eficientă a containerelor din **STL** pentru a asigura un cod modular și performant.

---

## ✨ Funcționalități Cheie
- **Gestiune Produse (CRUD):** Administrarea completă a produselor (ID, nume, preț, stoc).
- **Sistem de Plată & Rest:** Algoritm de calcul pentru eliberarea restului folosind monedele disponibile în tonomat.
- **Arhitectură Stratificată:** Separarea responsabilităților în straturi (Domain, Repository, Service, UI).
- **Persistența Datelor:** Salvarea și încărcarea automată a stării tonomatului din fișiere text/CSV.
- **Validare Robustă:** Tratarea cazurilor de eroare (fonduri insuficiente, produs indisponibil, input invalid).

---

## 🛠️ Stack Tehnologic
- **Limbaj:** C++ (Standard 14/17)
- **Biblioteci:** STL (std::vector, std::map, std::list, std::algorithm)
- **Gestiune Fișiere:** fstream (I/O Operations)
- **Arhitectură:** Layered Architecture (Separation of Concerns)

---

## 📂 Structura Proiectului
Codul este organizat modular pentru a fi ușor de întreținut și testat:

```text
src/
├── Entity/       # Entitățile de bază (Product, Money/Coin)
├── Repository/   # Gestiunea stocării (In-Memory & File Persistence)
├── Service/      # Logica de business (Tranzacții, Calcul Rest)
├── UI/           # Interfața cu utilizatorul (Meniu Consolă)
├── Test/        # Validarea funcționalităților (Unit Testing)
├── Validator/    #Validarea entitatilor
└── main.cpp     
