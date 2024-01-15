<?php
if (!function_exists('dms_fs')) {
    // Create a helper function for easy SDK access.
    function dms_fs()
    {
        global $dms_fs;

        if (!isset($dms_fs)) {
            // Include Freemius SDK.
            require_once dirname(__FILE__) . '/vendor/freemius/start.php';
            $dms_fs = fs_dynamic_init(array('id' => '6959', 'slug' => 'domain-mapping-system', 'premium_slug' => 'domain-mapping-system-pro', 'type' => 'plugin', 'public_key' => 'pk_e348807215df985c848c86b883ee3', 'is_premium' => true, 'premium_suffix' => 'PRO', 'has_addons' => false, 'has_paid_plans' => true, 'menu' => array('slug' => 'domain-mapping-system', 'support' => false, 'parent' => array('slug' => 'domain-mapping-system',),), 'is_live' => true,));
        }
    }
}