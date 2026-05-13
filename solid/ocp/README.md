# 開放封閉原則 (OCP) 實作案例：std::ostream 擴充

在 C++ 中，擴充 `std::ostream` 以支援自定義類別是遵循 OCP 的經典案例。我們不修改 `std::ostream` 的原始碼，而是透過重載 `operator<<` 來擴充其功能。

針對此擴充，主要有兩種實作方式，其優劣比較如下：

## 1. 友元函數 (Friend Function)
**對應檔案：** `ostream_friend.cpp`

透過在類別內部宣告 `friend`，讓 `operator<<` 可以直接存取私有成員（如 `first_`, `second_`, `some_other_data_`）。

*   **優點**：
    *   **保護內部細節**：不需為了列印而額外增加 Public 的 `getter` 介面，保持類別介面的簡潔（Minimal Interface）。
    *   **存取權限**：適合用於存取不應公開但需列印的內部狀態。
*   **缺點**：
    *   **封裝破壞**：`operator<<` 與類別的內部實作細節緊密綁定（Tightly Coupled）。若私有變數更名，此函數也必須修改。

## 2. 非成員、非友元函數 (Non-member, Non-friend Function)
**對應檔案：** `ostream_op_preferred.cpp`

僅透過類別提供的 Public 介面（如 `get_first()`, `get_second()`）來讀取資料。

*   **優點**：
    *   **封裝性最高 (Highest Encapsulation)**：這是最推薦的做法。`operator<<` 只依賴介面，不依賴實作細節。
    *   **低耦合**：類別內部的變動不會影響到外部的 `operator<<`。
*   **缺點**：
    *   **介面依賴**：必須確保類別有提供足夠的 Public 介面。如果某些資訊不想公開，就無法用此方式列印。

---

## 結論：哪個做法比較好？

根據軟體工程最佳實務（及 Scott Meyers 的建議）：

1.  **優先選擇：非成員、非友元函數**。只要 Public 介面足以提供所需的資訊，就應採用此方式。這能將封裝性最大化，並降低程式碼間的耦合。
2.  **次要選擇：友元函數**。只有在「不想為了列印而破壞封裝去開 getter」或「需要存取純私有狀態」時，才考慮使用 `friend`。

**總結：** 兩者都符合 OCP，但從封裝 (Encapsulation) 的角度來看，**「非成員、非友元函數」** 是更優的設計選擇。
