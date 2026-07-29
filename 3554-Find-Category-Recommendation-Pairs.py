import pandas as pd

def find_category_recommendation_pairs(product_purchases: pd.DataFrame, product_info: pd.DataFrame) -> pd.DataFrame:
    df = product_purchases.merge(product_info[['product_id', 'category']], on='product_id')
    
    user_categories = df[['user_id', 'category']].drop_duplicates()
    
    merged = user_categories.merge(user_categories, on='user_id', suffixes=('_1', '_2'))
    
    pairs = merged[merged['category_1'] < merged['category_2']]
    
    res = pairs.groupby(['category_1', 'category_2'])['user_id'].nunique().reset_index()
    res.columns = ['category1', 'category2', 'customer_count']
    
    res = res[res['customer_count'] >= 3]
    
    res = res.sort_values(
        by=['customer_count', 'category1', 'category2'],
        ascending=[False, True, True]
    )
    
    return res